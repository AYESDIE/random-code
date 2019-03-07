#include <iostream>
#include <armadillo>

void GetGroundTruthMatrix(
        const arma::Row<size_t>& labels,
        arma::sp_mat& groundTruth,
        size_t numClasses)
{
  // Calculate the ground truth matrix according to the labels passed. The
  // ground truth matrix is a matrix of dimensions 'numClasses * numExamples',
  // where each column contains a single entry of '1', marking the label
  // corresponding to that example.

  // Row pointers and column pointers corresponding to the entries.
  arma::uvec rowPointers(labels.n_elem);
  arma::uvec colPointers(labels.n_elem + 1);

  // Row pointers are the labels of the examples, and column pointers are the
  // number of cumulative entries made uptil that column.
  for (size_t i = 0; i < labels.n_elem; i++)
  {
    rowPointers(i) = labels(i);
    colPointers(i + 1) = i + 1;
  }

  // All entries are '1'.
  arma::vec values;
  values.ones(labels.n_elem);

  // Calculate the matrix.
  groundTruth = arma::sp_mat(rowPointers, colPointers, values, numClasses,
                             labels.n_elem);
}

int main()
{
  size_t numClasses = 3;
  double delta = 3.32;

  // A very simple fake dataset
  arma::mat dataset = "2 0 0;"
                      "0 0 0;"
                      "0 2 1;"
                      "1 0 2;"
                      "0 1 0";
  std::cout << "dataset \n" << dataset;

  //  Corresponding labels
  arma::Row<size_t> labels = "1 0 2";
  std::cout << "labels\n" << labels ;

  // Make ground truth matrix
  arma::sp_mat groundTruth, gt;
  GetGroundTruthMatrix(labels, groundTruth, numClasses);
  gt = groundTruth;
  std::cout << "groundTruth\n" << arma::conv_to<arma::mat>::from(gt);

  // A random set of parameters
  arma::mat parameters = "100 3 4 5 23;"
                         "43 54 67 32 64;"
                         "12 42 122 34 5";
  std::cout << "parameters\n" << parameters ;

  arma::mat scores = parameters * dataset;
  std::cout << "score\n" << scores;

  arma::mat correctScores = arma::repmat(arma::ones(numClasses).t()
                                         * (scores % groundTruth), numClasses, 1);
  std::cout << "correctSCores\n" << correctScores;

  arma::mat margin = scores - correctScores + delta
                     - (delta * groundTruth);

  std::cout << "margin\n" << margin;

  return 0;
}
