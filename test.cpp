#include "pch.h"
#include "Run.h"

//Google testing framework is used
TEST(TestCase, Example1) {
	size_t rows_p = 2, columns_p = 2;
	std::vector<std::string> pattern = {
		"10",
		"11"
	};

	size_t rows_m = 5, columns_m = 5;
	std::vector<std::string> matrix = {
		"11000",
		"01100",
		"10010",
		"11110",
		"00111"
	};
	
	std::vector<std::string> expected = {
		"12*00",
		"02200",
		"2*010",
		"2212*",
		"00122"
	};

	change_matrix(matrix, rows_m, columns_m, pattern, rows_p, columns_p);
	ASSERT_EQ(matrix, expected);
}

TEST(TestCase, Example2) {
	size_t rows_p = 1, columns_p = 1;
	std::vector<std::string> pattern = {
		"1"
	};

	size_t rows_m = 5, columns_m = 5;
	std::vector<std::string> matrix = {
		"11000",
		"01100",
		"10010",
		"11110",
		"00111"
	};

	std::vector<std::string> expected = {
		"22000",
		"02200",
		"20020",
		"22220",
		"00222"
	};

	change_matrix(matrix, rows_m, columns_m, pattern, rows_p, columns_p);
	ASSERT_EQ(matrix, expected);
}

TEST(TestCase, Example3) {
	size_t rows_p = 1, columns_p = 1;
	std::vector<std::string> pattern = {
		"0"
	};

	size_t rows_m = 5, columns_m = 5;
	std::vector<std::string> matrix = {
		"11000",
		"01100",
		"10010",
		"11110",
		"00111"
	};

	std::vector<std::string> expected = {
		"11***",
		"*11**",
		"1**1*",
		"1111*",
		"**111"
	};

	change_matrix(matrix, rows_m, columns_m, pattern, rows_p, columns_p);
	ASSERT_EQ(matrix, expected);
}

TEST(TestCase, Example4) {
	size_t rows_p = 2, columns_p = 6;
	std::vector<std::string> pattern = {
		"100101",
		"111010"
	};

	size_t rows_m = 5, columns_m = 5;
	std::vector<std::string> matrix = {
		"11000",
		"01100",
		"10010",
		"11110",
		"00111"
	};

	std::vector<std::string> expected = {
		"11000",
		"01100",
		"10010",
		"11110",
		"00111"
	};

	change_matrix(matrix, rows_m, columns_m, pattern, rows_p, columns_p);
	ASSERT_EQ(matrix, expected);
}

TEST(TestCase, Empty) {
	size_t rows_p = 0, columns_p = 0;
	std::vector<std::string> pattern;

	size_t rows_m = 5, columns_m = 5;
	std::vector<std::string> matrix = {
		"11000",
		"01100",
		"10010",
		"11110",
		"00111"
	};

	std::vector<std::string> expected = {
		"11000",
		"01100",
		"10010",
		"11110",
		"00111"
	};

	change_matrix(matrix, rows_m, columns_m, pattern, rows_p, columns_p);
	ASSERT_EQ(matrix, expected);
}

TEST(TestCase, Big) {
	size_t rows_p = 2, columns_p = 20;
	std::vector<std::string> pattern = {
		"11111111111111111111",
		"00000000000000000000"
	};
	size_t rows_m = 50, columns_m = 100;
	std::vector<std::string> matrix = {
		"1111111111111111111100101000110001000110010100011000100011001010001100010001001011111111111111111111",//0
		"0000000000000000000000101100101000110001000110010100011000011111100101000110001000000000000000000000",//1
		"1001010001100010001100101000110001000100011000100011111100101000110001000110110010100011000100011001",//2
		"1100010001111110010100011000100011001011001010001100010001100010110010100011000100001100101000110001",//3
		"1001010001100010001000111111001010001100010001100101000110001000111001010001100010000110010100011000",//4
		"1001011010001100010001100101000110001000100010001111110010100011000100011000101000110100101000110010",//5
		"0010100011000100011001010001100010001111111111111111111111100110010100011000100001100001100101000111",//6
		"1001010001100010000100011111011001010000000000000000000010100101000110000100011001000110001000110001",//7
		"1001010001100010001100101000110001000110010100011000100011001010001100010001000010100011000100011111",//8
		"1001010001100010001100101000110001000110010100011000100011001010100011001010000110001000010001100010",//9
		"1001010001100010001100101000110001000110010100011000100011001001000110001000110010100011000100011111",//10
		"1001110101100010011000101100101000110001000110010100011000011111100101000011000100011001010001100001",//11
		"1001010001100010001100101000110001000100011000100011111100101000011000100011011001010001100010001101",//12
		"1100010001111110010100011000100011001011001010001100010001100010110010010001100010001100101000110001",//1
		"1001010001100010001000111111001010001100010001100101000110000100011100101000110001000110010100011000",//14
		"1001011010001100010001100111111111111111111110100011111100101000110000100011001010110010100011000101",//15
		"0010100011000100011001010000000000000000000000110001000111100101001010100110001001001110101100010011",
		"1001010001100010000100011111011001010001100010001100010001100101000110000100011001000110001000110001",
		"1001010001100010001100101000110001000110010100011000100011001010001100001000110010100011000100011111",
		"1001010001100010001100101000110001000110010100011000100011001010100001100101000110001000010001100010",
		"1001010001100010001100101000110001000110010100011000100011001010001100010000110010100011000100011111",
		"1001110101100010011000101100101000110001000110010100011000011111100101000011000100011001010001100001",
		"1001010001100010001100101000110001000100011000100011111100101000110001000011011001010001100010001101",
		"1100010001111110010100011000100011001011001010001100010001100010110010100001100010001100101000110001",
		"1001010001100010001000111111001010001100010001100101000110001000111001001000110001000110010100011000",
		"1001011010001100010001100101000110001000100010001111110010100011000100011000101000111001010001100010",
		"0010100011000100011001010001100010001100101000110001000111100110010100011000010001100001100101000111",
		"1001010001100010000100011111011001010001100010001100010001100101000110001000011001000110001000110001",
		"1001010001100010001100101000110001000110010100011000100011001010001100010001010010100011000100011111",
		"1001010001100010001100101000110001000110010100011000100011001010100011001010000110001000010001100010",
		"1001010001100010001100101000110001000110010100011000010001100101000110001000110010100011000100011111",
		"1001110101100010011000101100101000110001000110010100001100001111110010100011000100011001010001100001",
		"1001010001100010001100101000110001000100011000100011111111111111111111110101001100101001100010001101",
		"1100010001111110010100011000100011001011001010001100000000000000000000010001100010001100101000110001",
		"1001010001100010001000111111001010001100010001100101000011000100011100101000110001000110010100011000",
		"1001011010111111111111111111110011000100010001000111111000101000110000001100101000111001010001100010",
		"0010100011000000000000000000000010001100101000110001000011110011001010001100010001100001100101000111",
		"1001010001100010000100011111011001010001100010001100010000110010100011000100011001000110001000110001",
		"1001010001100010001100101000110001000110010100011000100001100101000110001000110010100011000100011111",
		"1001010001100010001100101000110001000110010100011000100010100101010001100101000110001000010001100010",
		"1001010001100010001100101000110001000110010100011000100011000101000110001000110010100011000100011111",
		"1001110101100010011000101100101000110001000110010100011000001111110010100011000100011001010001100001",
		"1001010001100010001100101000110001000100011000100011111100100100011000100011011001010001100010001101",
		"1100010001111110010100011000100011001011001010001100010001100001011001010001100010001100101000110001",
		"1001010001100010001000111111001010001100010001100101000110001000011100101000110001000110010100011000",
		"1001011010001100010001100101000110001000100010001111110010100010100010001100101000111001010001100010",
		"0010100011000100011001010001100010001100101000110001000111100110001010001100010001100001100101000111",
		"1001010001100010000100011111011001010001100010001100010001100101000011000100011001000110001000110001",
		"1001010001100010001100101000110001000110010100011000100011001010000110001000110010100011000100011111",
		"1001010001100010001100101000110001000110010100011000100011001010100001100101000110001000010001100010"
	};
	std::vector<std::string> expected = {
		"2222222222222222222200101000110001000110010100011000100011001010001100010001001022222222222222222222",
		"********************001011001010001100010001100101000110000111111001010001100010********************",
		"1001010001100010001100101000110001000100011000100011111100101000110001000110110010100011000100011001",
		"1100010001111110010100011000100011001011001010001100010001100010110010100011000100001100101000110001",
		"1001010001100010001000111111001010001100010001100101000110001000111001010001100010000110010100011000",
		"1001011010001100010001100101000110001000100010001111110010100011000100011000101000110100101000110010",
		"0010100011000100011001010001100010002222222222222222222211100110010100011000100001100001100101000111",
		"100101000110001000010001111101100101********************10100101000110000100011001000110001000110001",
		"1001010001100010001100101000110001000110010100011000100011001010001100010001000010100011000100011111",
		"1001010001100010001100101000110001000110010100011000100011001010100011001010000110001000010001100010",
		"1001010001100010001100101000110001000110010100011000100011001001000110001000110010100011000100011111",
		"1001110101100010011000101100101000110001000110010100011000011111100101000011000100011001010001100001",
		"1001010001100010001100101000110001000100011000100011111100101000011000100011011001010001100010001101",
		"1100010001111110010100011000100011001011001010001100010001100010110010010001100010001100101000110001",
		"1001010001100010001000111111001010001100010001100101000110000100011100101000110001000110010100011000",
		"1001011010001100010001100222222222222222222220100011111100101000110000100011001010110010100011000101",
		"0010100011000100011001010********************0110001000111100101001010100110001001001110101100010011",
		"1001010001100010000100011111011001010001100010001100010001100101000110000100011001000110001000110001",
		"1001010001100010001100101000110001000110010100011000100011001010001100001000110010100011000100011111",
		"1001010001100010001100101000110001000110010100011000100011001010100001100101000110001000010001100010",
		"1001010001100010001100101000110001000110010100011000100011001010001100010000110010100011000100011111",
		"1001110101100010011000101100101000110001000110010100011000011111100101000011000100011001010001100001",
		"1001010001100010001100101000110001000100011000100011111100101000110001000011011001010001100010001101",
		"1100010001111110010100011000100011001011001010001100010001100010110010100001100010001100101000110001",
		"1001010001100010001000111111001010001100010001100101000110001000111001001000110001000110010100011000",
		"1001011010001100010001100101000110001000100010001111110010100011000100011000101000111001010001100010",
		"0010100011000100011001010001100010001100101000110001000111100110010100011000010001100001100101000111",
		"1001010001100010000100011111011001010001100010001100010001100101000110001000011001000110001000110001",
		"1001010001100010001100101000110001000110010100011000100011001010001100010001010010100011000100011111",
		"1001010001100010001100101000110001000110010100011000100011001010100011001010000110001000010001100010",
		"1001010001100010001100101000110001000110010100011000010001100101000110001000110010100011000100011111",
		"1001110101100010011000101100101000110001000110010100001100001111110010100011000100011001010001100001",
		"1001010001100010001100101000110001000100011000100022222222222222222222210101001100101001100010001101",
		"11000100011111100101000110001000110010110010100011*********************10001100010001100101000110001",
		"1001010001100010001000111111001010001100010001100101000011000100011100101000110001000110010100011000",
		"1001011010222222222222222222220011000100010001000111111000101000110000001100101000111001010001100010",
		"0010100011********************0010001100101000110001000011110011001010001100010001100001100101000111",
		"1001010001100010000100011111011001010001100010001100010000110010100011000100011001000110001000110001",
		"1001010001100010001100101000110001000110010100011000100001100101000110001000110010100011000100011111",
		"1001010001100010001100101000110001000110010100011000100010100101010001100101000110001000010001100010",
		"1001010001100010001100101000110001000110010100011000100011000101000110001000110010100011000100011111",
		"1001110101100010011000101100101000110001000110010100011000001111110010100011000100011001010001100001",
		"1001010001100010001100101000110001000100011000100011111100100100011000100011011001010001100010001101",
		"1100010001111110010100011000100011001011001010001100010001100001011001010001100010001100101000110001",
		"1001010001100010001000111111001010001100010001100101000110001000011100101000110001000110010100011000",
		"1001011010001100010001100101000110001000100010001111110010100010100010001100101000111001010001100010",
		"0010100011000100011001010001100010001100101000110001000111100110001010001100010001100001100101000111",
		"1001010001100010000100011111011001010001100010001100010001100101000011000100011001000110001000110001",
		"1001010001100010001100101000110001000110010100011000100011001010000110001000110010100011000100011111",
		"1001010001100010001100101000110001000110010100011000100011001010100001100101000110001000010001100010"
	};
	change_matrix(matrix, rows_m, columns_m, pattern, rows_p, columns_p);
	ASSERT_EQ(matrix, expected);
}