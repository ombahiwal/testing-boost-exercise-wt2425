#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"
#include <Eigen/Dense>

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(TestOpenData_ValidFile)
{
  // Arrange
  const std::string validFilePath = "../data/matrix.csv"; // Ensure this file exists
  const int         matrixSize    = 3;

  // Act
  Eigen::MatrixXd resultMatrix = matrixIO::openData(validFilePath, matrixSize);

  // Assert
  BOOST_TEST(resultMatrix.rows() == matrixSize);
  BOOST_TEST(resultMatrix.cols() == matrixSize);
}

BOOST_AUTO_TEST_SUITE_END()
