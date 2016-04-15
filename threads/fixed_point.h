////Fixed Point arithmatic for PintOS Version 1.0
////Used in the Multi-Level Feedback Que
////All return values are in 17.14 fixed point arithmatic
//#include <stdlib.h>
////#include <assert.h>
//
//#include <stdio.h> // for perror()
//
////Converted integer type
typedef struct fixed_point {
	int value;
} converted_int, fixed_pt;
//// int some_function(void);
//static converted_int converter(int toBeConverted);
//static int inverter(converted_int toBeInverted);
//static converted_int convertFraction(int numerator, int denominator);
//static converted_int additionN(int first, int second);
//static converted_int additionNC (int normal, converted_int converted);
//static converted_int additionC (converted_int first, converted_int second);
//static converted_int subtractionN(int first, int second);
//static converted_int subtractionNC (int normal, converted_int converted);
//static converted_int subtractionCN (converted_int converted, int normal);
//static converted_int subtractionC (converted_int first, converted_int second);
//static converted_int multiplicationN(int first, int second);
//static converted_int multiplicationNC (int normal, converted_int converted);
//static converted_int multiplicationCN (converted_int converted, int normal);
//static converted_int multiplicationC (converted_int first, converted_int second);
//static converted_int divisionN(int first, int second);
//static converted_int divisionNC (int normal, converted_int converted);
//static converted_int divisionCN (converted_int converted, int normal);
//static converted_int divisionC (converted_int first, converted_int second);
//static converted_int create_fixed_pt(int integer);
//
//
//
//static converted_int create_fixed_pt(int integer){
//	return converter(integer);
//}
//
////Converter
//static converted_int converter(int toBeConverted) {
//	if( toBeConverted >= 131072) { //check if out of bounds
//		//assert(1 == 0);
//	}
//	if( toBeConverted <= -131072) { //more checking
//		//assert(1 == 0);
//	}
//	converted_int newInt;
//	newInt.value = toBeConverted*16384;
//	return newInt; // returning converted value
//}
//
////Inverter
//static int inverter(converted_int toBeInverted) {
//	return ((toBeInverted.value)/16384);//// returning inverted value
//}
//
////Converter for fractions (division)
//static converted_int convertFraction(int numerator, int denominator) {
//	converted_int quotient;
//	quotient = converter(numerator); //sending our numerator to be converted
//	//quotient.value = quotient.value / denominator;
//	quotient.value = (quotient.value + (converter(denominator).value/2)) / denominator; //doing converted evaluation
//	return quotient; // returning converted value
//}
//
////Addition between two normal
//static converted_int additionN(int first, int second) {
//	converted_int newInt;
//	newInt = converter(first + second);
//	return newInt;
//}
//
////Addition between one normal then one converted
//static converted_int additionNC (int normal, converted_int converted) {
//	converted_int newInt;
//	newInt.value = converter(normal).value + converted.value;
//	return newInt;
//}
//
////Addition between two converted
//static converted_int additionC (converted_int first, converted_int second) {
//	converted_int newInt;
//	newInt.value = first.value + second.value;
//	return newInt;
//}
//
////Subtraction between two normal
//static converted_int subtractionN (int first, int second) {
//	converted_int newInt;
//	newInt = converter(first - second);
//	return newInt;
//}
//
////Subtraction between one normal then one converted
//static converted_int subtractionNC (int normal, converted_int converted) {
//	converted_int newInt;
//	newInt.value = converter(normal).value - converted.value;
//	return newInt;
//}
//
////Subtraction between one converted then one normal
//static converted_int subtractionCN (converted_int converted, int normal) {
//	converted_int newInt;
//	newInt.value = converted.value - converter(normal).value;
//	return newInt;
//}
//
////Subtraction between two converted
//static converted_int subtractionC (converted_int first, converted_int second) {
//	converted_int newInt;
//	newInt.value = first.value - second.value;
//	return newInt;
//}
//
////Multiplication between two normal
//static converted_int multiplicationN (int first, int second) {
//	converted_int newInt;
//	newInt = converter(first*second);
//	return newInt;
//}
//
////Multiplication between one normal then one converted
//static converted_int multiplicationNC (int normal, converted_int converted) {
//	converted_int newInt;
//	newInt.value = normal*converted.value;
//	return newInt;
//}
//
////Multiplication between one converted then one normal
//static converted_int multiplicationCN (converted_int converted, int normal) {
//	converted_int newInt;
//	newInt.value = converted.value*normal;
//	return newInt;
//}
//
////Multiplication between two converted
//static converted_int multiplicationC (converted_int first, converted_int second) {
//	converted_int newInt;
//	newInt.value = (((int64_t) first.value) * second.value) / 16384;
//	return newInt;
//}
//
////Division between two normal
//static converted_int divisionN (int first, int second) {
//	converted_int newInt;
//	newInt = convertFraction(first, second);
//	return newInt;
//}
//
////Division between one normal then one converted
//static converted_int divisionNC (int normal, converted_int converted) {
//	converted_int newInt;
//	newInt = convertFraction(normal, inverter(converted)); //Using inverter to cheat
//	return newInt;
//}
//
////Division between one converted then one normal
//static converted_int divisionCN (converted_int converted, int normal) {
//	converted_int newInt;
//	newInt = convertFraction(inverter(converted), normal); //Using inverter to cheat
//	return newInt;
//}
//
////Division between two converted
//static converted_int divisionC (converted_int first, converted_int second) {
//	converted_int newInt;
//	newInt = convertFraction(inverter(first), inverter(second)); //Using inverter to doubly cheat
//	return newInt;
//}
//
///* main */ //Print tests for FPA
///*int main(int argc, char *argv[]) {
//
//    int x = -50;
//    int y = 100;
//    struct _converted_int x_fixed, y_fixed;
//    x_fixed = converter(x);
//    y_fixed = converter(y);
//
//    struct _converted_int fixed_result;
//    int inverted_result;
//    fixed_result = subtractionN(x,y);
//    inverted_result = inverter(fixed_result);
//
//    printf("\n");
//    printf("%s\n", "subtraction:");
//    printf("%s%d\n", "fixed value: ", subtractionNC(x, y_fixed).value);
//    printf("%s%d\n", "inverted value: ", inverter(subtractionNC(x, y_fixed)));
//
//    printf("%s%d\n", "fixed value: ", subtractionCN(y_fixed, x).value);
//    printf("%s%d\n", "inverted value: ", inverter(subtractionCN(y_fixed, x)));
//
//    printf("%s%d\n", "fixed value: ", subtractionN(x,y).value);
//    printf("%s%d\n", "inverted value: ", inverted_result);
//
//    printf("%s%d\n", "fixed value: ", subtractionC(x_fixed, y_fixed).value);
//    printf("%s%d\n", "inverted value: ", inverter(subtractionC(x_fixed, y_fixed)));
//
//    printf("\n");
//    printf("%s\n", "addition:");
//    printf("%s%d\n", "fixed value: ", additionNC(x, y_fixed).value);
//    printf("%s%d\n", "inverted value: ", inverter(additionNC(x, y_fixed)));
//
//    printf("%s%d\n", "fixed value: ", additionN(x,y).value);
//    printf("%s%d\n", "inverted value: ", inverter(additionN(x,y)));
//
//    printf("%s%d\n", "fixed value: ", additionC(x_fixed, y_fixed).value);
//    printf("%s%d\n", "inverted value: ", inverter(additionC(x_fixed, y_fixed)));
//
//    printf("\n");
//    printf("%s\n", "multiplication:");
//    printf("%s%d\n", "fixed value: ", multiplicationNC(x, y_fixed).value);
//    printf("%s%d\n", "inverted value: ", inverter(multiplicationNC(x, y_fixed)));
//
//    printf("%s%d\n", "fixed value: ", multiplicationN(x,y).value);
//    printf("%s%d\n", "inverted value: ", inverter(multiplicationN(x,y)));
//
//    printf("%s%d\n", "fixed value: ", multiplicationC(x_fixed, y_fixed).value);
//    printf("%s%d\n", "inverted value: ", inverter(multiplicationC(x_fixed, y_fixed)));
//
//    printf("\n");
//    printf("%s\n", "division:");
//    printf("%s%d\n", "fixed value: ", divisionNC(x, y_fixed).value);
//    printf("%s%d\n", "inverted value: ", inverter(divisionNC(x, y_fixed)));
//
//    printf("%s%d\n", "fixed value: ", divisionCN(y_fixed, x).value);
//    printf("%s%d\n", "inverted value: ", inverter(divisionCN(y_fixed, x)));
//
//    printf("%s%d\n", "fixed value: ", divisionN(x,y).value);
//    printf("%s%d\n", "inverted value: ", inverter(divisionN(x,y)));
//
//    printf("%s%d\n", "fixed value: ", divisionC(x_fixed, y_fixed).value);
//    printf("%s%d\n", "inverted value: ", inverter(divisionC(x_fixed, y_fixed)));
//*/
//
////     return 0;
//// }