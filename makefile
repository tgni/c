CCFLAGS = -W -Wall -I..
LDFLAGS = -lm

# executable files for this directory
TARGETEXE = a_plus_1.exe align.exe alloca_test.exe array.exe atof.exe attribute.exe backslash.exe \
	  baud.exe clock.exe compare_time.exe const.exe count_char.exe data.exe double.exe ending.exe \
	  eoftest.exe exit_code.exe f2ctbl.exe float.exe fork.exe freenull.exe hello.exe helloworld.exe \
	  in2out.exe init.exe invalid_mem.exe itoa.exe lexical.exe line_longer_than_80.exe list.exe \
	  longest_line.exe macro.exe mem_zero.exe nulltest.exe pointarray.exe print_words_length.exe \
	  privilege.exe ptr.exe putBits.exe random.exe restrict.exe reverse.exe same_var_and_func.exe \
	  series.exe shift.exe signedchar.exe sorting_list.exe sqrt.exe squeeze.exe stack_mem.exe \
	  test.exe test_global_local_same.exe test_pointer.exe testwhile.exe trim_blanks.exe visible.exe \
	  word_per_line.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include GNU_makefile_template
