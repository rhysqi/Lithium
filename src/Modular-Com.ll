define i64 @Lithium()
{
	%ret_i64 = call i64 @Real_Lithium()
	%ret_i32 = trunc i64 %ret_i64 to i32
	ret i32 %ret_i32
}

define i64 @Real_Lithium()
{
	
}