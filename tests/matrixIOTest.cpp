#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(TestOpenData_ValidFile)
{
  // Arrange
  const std::string validFilePath = "../data/m3.csv"; // Ensure this file exists
  const int         matrixSize    = 3;

  // Act
  Eigen::MatrixXd resultMatrix = matrixIO::openData(validFilePath, matrixSize);

  // Assert
  BOOST_TEST(resultMatrix.rows() == matrixSize);
  BOOST_TEST(resultMatrix.cols() == matrixSize);
}

BOOST_AUTO_TEST_SUITE_END()
