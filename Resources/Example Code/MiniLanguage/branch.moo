SET_VAR 	0 2			# Var 0 = 2
SET_VAR 	1 3			# Var 1 = 3
SET_VAR 	2 3			# Var 1 = 3

PRINT_TEXT 		var 0 =
PRINT_VAR 0
PRINT_ENDL

PRINT_TEXT 		var 1 =
PRINT_VAR 1
PRINT_ENDL

PRINT_TEXT 		var 2 =
PRINT_VAR 2
PRINT_ENDL

IF_EQ 0 1 # if var 0 == var 1
	PRINT_TEXT 0 and 1 - equal
	PRINT_VAR 0
	PRINT_VAR 1
END_IF

IF_NEQ 0 1 # if var 0 != var 1
	PRINT_TEXT 0 and 1 - not equal
	PRINT_VAR 0
	PRINT_VAR 1
END_IF


IF_EQ 1 2 # if var 1 == var 2
	PRINT_TEXT 1 and 2 - equal
	PRINT_VAR 1
	PRINT_VAR 2
END_IF

IF_NEQ 1 2 # if var 1 != var 2
	PRINT_TEXT 1 and 2 - not equal
	PRINT_VAR 1
	PRINT_VAR 2
END_IF

PRINT_TEXT end of program

