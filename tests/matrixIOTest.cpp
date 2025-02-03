#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp" // Assuming this is where openData is located

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(TestOpenData_ValidFile)
{
  // Arrange
  const std::string validFilePath = "../data/matrix.csv"; // Update path as needed
  const int         matrixSize    = 3;                    // Specify the expected matrix size
  MatrixIO          matrixIO;

  // Act
  MatrixXd resultMatrix = matrixIO.openData(validFilePath, matrixSize);

  // Assert
  BOOST_TEST(resultMatrix.rows() == matrixSize); // Ensure rows are correct
  BOOST_TEST(resultMatrix.cols() == matrixSize); // Ensure columns are correct

  // Verify the contents of the matrix (You can use a few entries as expected)
  BOOST_TEST(resultMatrix(0, 0) == 1.0);
  BOOST_TEST(resultMatrix(0, 1) == 2.0);
  BOOST_TEST(resultMatrix(0, 2) == 3.0);
}

BOOST_AUTO_TEST_CASE(TestOpenData_FileNotFound)
{
  // Arrange
  const std::string invalidFilePath = "../data/nonexistent_matrix.csv";
  const int         matrixSize      = 3;
  MatrixIO          matrixIO;

  // Act & Assert
  BOOST_CHECK_THROW(matrixIO.openData(invalidFilePath, matrixSize), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(TestOpenData_InvalidMatrixSize)
{
  // Arrange
  const std::string invalidSizeFilePath = "../data/matrix_invalid_size.csv";
  const int         matrixSize          = 3; // We expect 3x3, but the file may have a different size
  MatrixIO          matrixIO;

  // Act & Assert
  BOOST_CHECK_THROW(matrixIO.openData(invalidSizeFilePath, matrixSize), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()