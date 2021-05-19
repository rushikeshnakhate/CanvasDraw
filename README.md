**Scope**
1.	There is duplicate code and it need refcatoring  
2.	Current application does not use configuration, Config file can be used to enable/disable specific shape.
3.  Application does not support for bdd feature ,I have just added a sample feature file.
4.	Application uses gtes as test library and it is provided with package .
5.	I have tried to keep it very simple and did not use any external library , specificaly Boost , the code can be further simplified using boost .
6.	used simple cout for logging the information 
7.	Single threaded application 




**INSTALLATION:**

1.	Directory structure 
`"""
└───CanvasDraw
    ├───src
    │   ├───main
    │   │   ├───canvaspage
    │   │   │   └───impl
    │   │   ├───client
    │   │   ├───common
    │   │   │   └───impl
    │   │   ├───menu
    │   │   │   └───impl
    │   │   ├───processor
    │   │   │   └───impl
    │   │   ├───resource
    │   │   └───shape
    │   │       └───impl
    │   └───test
    │       ├───feature
    │       │   ├───bdd
    │       │   └───tdd
    │       ├───menu
    │       ├───processor
    │       ├───resource
    │       └───shape
    └───thirdparty
        ├───ci
        ├───docs
        │   ├───assets
        │   │   └───css
        │   ├───reference
        │   ├───_data
        │   ├───_layouts
        │   └───_sass
        ├───googlemock
        │   ├───cmake
        │   ├───docs
        │   ├───include
        │   │   └───gmock
        │   │       └───internal
        │   │           └───custom
        │   ├───scripts
        │   │   └───generator
        │   │       └───cpp
        │   ├───src
        │   └───test
        └───googletest
            ├───cmake
            ├───docs
            ├───include
            │   └───gtest
            │       └───internal
            │           └───custom
            ├───samples
            ├───scripts
            │   └───test
            ├───src
            └───test
`"""
2.	a.DownLoad the dolder 
	b.uncompress it 
	
3.  Build Using Clion on Window 
	a.open the project using clion 
	b.main menu -> Build -> Run the Test 
	c.main menu -> Build -> Run the Application 
	
	
4.  Build on Linux 
	a. cmake CMakefile.txt
	"""
	-- The C compiler identification is GNU 7.5.0
	-- The CXX compiler identification is GNU 7.5.0
	-- Check for working C compiler: /usr/bin/cc
	-- Check for working C compiler: /usr/bin/cc -- works
	-- Detecting C compiler ABI info
	-- Detecting C compiler ABI info - done
	-- Detecting C compile features
	-- Detecting C compile features - done
	-- Check for working CXX compiler: /usr/bin/c++
	-- Check for working CXX compiler: /usr/bin/c++ -- works
	-- Detecting CXX compiler ABI info
	-- Detecting CXX compiler ABI info - done
	-- Detecting CXX compile features
	-- Detecting CXX compile features - done
	-- Found Python: /usr/bin/python3.6 (found version "3.6.9") found components:  Interpreter
	-- Looking for pthread.h
	-- Looking for pthread.h - found
	-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
	-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
	-- Looking for pthread_create in pthreads
	-- Looking for pthread_create in pthreads - not found
	-- Looking for pthread_create in pthread
	-- Looking for pthread_create in pthread - found
	-- Found Threads: TRUE
	-- Configuring done
	-- Generating done
	-- Build files have been written to: /home/rushi/CanvasDraw
	"""
	
	
  b. make 
  
		Scanning dependencies of target gtest
		[  2%] Building CXX object thirdparty/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
		[  5%] Linking CXX static library ../../lib/libgtest.a
		[  5%] Built target gtest
		Scanning dependencies of target gmock
		[  8%] Building CXX object thirdparty/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
		[ 11%] Linking CXX static library ../../lib/libgmock.a
		[ 11%] Built target gmock
		Scanning dependencies of target gmock_main
		[ 14%] Building CXX object thirdparty/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
		[ 17%] Linking CXX static library ../../lib/libgmock_main.a
		[ 17%] Built target gmock_main
		Scanning dependencies of target gtest_main
		[ 20%] Building CXX object thirdparty/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
		[ 23%] Linking CXX static library ../../lib/libgtest_main.a
		[ 23%] Built target gtest_main
		Scanning dependencies of target CanvasMain
		[ 26%] Building CXX object src/main/CMakeFiles/CanvasMain.dir/menu/impl/IMenu.cpp.o
		[ 29%] Building CXX object src/main/CMakeFiles/CanvasMain.dir/processor/impl/IProcessor.cpp.o
		[ 32%] Building CXX object src/main/CMakeFiles/CanvasMain.dir/shape/impl/Canvas.cpp.o
		[ 35%] Building CXX object src/main/CMakeFiles/CanvasMain.dir/shape/impl/Line.cpp.o
		[ 38%] Building CXX object src/main/CMakeFiles/CanvasMain.dir/shape/impl/FillArea.cpp.o
		[ 41%] Building CXX object src/main/CMakeFiles/CanvasMain.dir/shape/impl/Rectangle.cpp.o
		[ 44%] Building CXX object src/main/CMakeFiles/CanvasMain.dir/common/impl/Utils.cpp.o
		[ 47%] Building CXX object src/main/CMakeFiles/CanvasMain.dir/Main.cpp.o
		[ 50%] Building CXX object src/main/CMakeFiles/CanvasMain.dir/canvaspage/impl/ICanvasPage.cpp.o
		[ 52%] Linking CXX executable CanvasMain
		[ 52%] Built target CanvasMain
		Scanning dependencies of target CanvasTest
		[ 55%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/mainTest.cpp.o
		[ 58%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/menu/TestIMenu.cpp.o
		[ 61%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/processor/TestIProcessor.cpp.o
		[ 64%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/shape/TestILine.cpp.o
		[ 67%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/shape/TestFillArea.cpp.o
		[ 70%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/shape/TestCanvas.cpp.o
		[ 73%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/feature/tdd/TestAppl.cpp.o
		[ 76%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/__/main/menu/impl/IMenu.cpp.o
		[ 79%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/__/main/processor/impl/IProcessor.cpp.o
		[ 82%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/__/main/shape/impl/Canvas.cpp.o
		[ 85%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/__/main/shape/impl/Line.cpp.o
		[ 88%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/__/main/shape/impl/FillArea.cpp.o
		[ 91%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/__/main/shape/impl/Rectangle.cpp.o
		[ 94%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/__/main/common/impl/Utils.cpp.o
		[ 97%] Building CXX object src/test/CMakeFiles/CanvasTest.dir/__/main/canvaspage/impl/ICanvasPage.cpp.o
		[100%] Linking CXX executable CanvasTest
		[100%] Built target CanvasTest
		rushi@RUSHI-PC:~/CanvasDraw$


	c.	Ruh the Test 
	   cd src/test ; ./CanvasTest ;
	   
	   """
		[==========] Running 11 tests from 6 test suites.
		[----------] Global test environment set-up.
		[----------] 1 test from TestIMenu
		[ RUN      ] TestIMenu.when_item_configured_then_its_added
		[       OK ] TestIMenu.when_item_configured_then_its_added (0 ms)
		[----------] 1 test from TestIMenu (3 ms total)

		[----------] 2 tests from TestIProcessor
		[ RUN      ] TestIProcessor.when_correct_option_choosen_then_its_accepted
		----
		|  |
		----
		[       OK ] TestIProcessor.when_correct_option_choosen_then_its_accepted (1 ms)
		[ RUN      ] TestIProcessor.when_incorrect_shape_choosen_then_its_reported
		Error:Incorrect Option provided,received=INCORRECT,please check menu and try with correct option
		Incorrect option passed='INCORRECT',Please check menu options and try again
		[       OK ] TestIProcessor.when_incorrect_shape_choosen_then_its_reported (1 ms)
		[----------] 2 tests from TestIProcessor (9 ms total)

		[----------] 3 tests from TestILine
		[ RUN      ] TestILine.Given_canvas_not_exists_then_line_cannot_be_drawn
		canvas does not exits,please create canvas before creating Line
		[       OK ] TestILine.Given_canvas_not_exists_then_line_cannot_be_drawn (4 ms)
		[ RUN      ] TestILine.when_drawLine_outside_width_then_contraint_validated
		----------------------
		|                    |
		|                    |
		|                    |
		|                    |
		----------------------
		Incorrect argument passed,expected=B x y c,actual received='B 22 1 '
		[       OK ] TestILine.when_drawLine_outside_width_then_contraint_validated (14 ms)
		[ RUN      ] TestILine.when_drawLine_outside_height_then_contraint_validated
		----------------------
		|                    |
		|                    |
		|                    |
		|                    |
		----------------------
		Incorrect argument passed,expected=B x y c,actual received='B 20 1 '
		[       OK ] TestILine.when_drawLine_outside_height_then_contraint_validated (14 ms)
		[----------] 3 tests from TestILine (39 ms total)

		[----------] 3 tests from TestFillArea
		[ RUN      ] TestFillArea.Given_canvas_not_exists_then_fillArea_cannot_be_drawn
		canvas does not exits,please create canvas before creating Rectangle
		[       OK ] TestFillArea.Given_canvas_not_exists_then_fillArea_cannot_be_drawn (0 ms)
		[ RUN      ] TestFillArea.when_drawfill_requested_then_its_contraint_respected
		----------------------
		|                    |
		|                    |
		|                    |
		|                    |
		----------------------
		Incorrect argument passed,expected=B x y c,actual received='B 22 1 '
		[       OK ] TestFillArea.when_drawfill_requested_then_its_contraint_respected (14 ms)
		[ RUN      ] TestFillArea.when_drawfill_outside_canvas_requested_then_its_contraint_respected
		----------------------
		|                    |
		|                    |
		|                    |
		|                    |
		----------------------
		Error:Dimension requested are outside canvas area,expected canvas width=22 canvas height=6 actual received width=25 height=1
		[       OK ] TestFillArea.when_drawfill_outside_canvas_requested_then_its_contraint_respected (14 ms)
		[----------] 3 tests from TestFillArea (33 ms total)

		[----------] 1 test from TestCanvas
		[ RUN      ] TestCanvas.when_negative_values_are_passed_canvas_not_created
		Canvas width or height cannot be negative received height=4 width=-20
		Incorrect argument passed,expected=B x y c,actual received='B 22 1 '
		[       OK ] TestCanvas.when_negative_values_are_passed_canvas_not_created (5 ms)
		[----------] 1 test from TestCanvas (6 ms total)

		[----------] 1 test from TestAppl
		[ RUN      ] TestAppl.running_all_input_cases
		----------------------
		|                    |
		|                    |
		|                    |
		|                    |
		----------------------
		----------------------
		|                    |
		|xxxxxx              |
		|                    |
		|                    |
		----------------------
		----------------------
		|                    |
		|xxxxxx              |
		|     x              |
		|     x              |
		----------------------
		----------------------
		|             xxxxx  |
		|xxxxxx       x   x  |
		|     x       xxxxx  |
		|     x              |
		----------------------
		----------------------
		|oooooooooooooxxxxxoo|
		|xxxxxxooooooox   xoo|
		|     xoooooooxxxxxoo|
		|     xoooooooooooooo|
		----------------------
		Application Quit request is received , App would stop now
		[       OK ] TestAppl.running_all_input_cases (36 ms)
		[----------] 1 test from TestAppl (38 ms total)

		[----------] Global test environment tear-down
		[==========] 11 tests from 6 test suites ran. (146 ms total)
		[  PASSED  ] 11 tests.
			   
	   
	    """
		
		
		d.  Run the Application
			cd src/main ;./CanvasMain
				
			 'C' Should create a new canvas CanvasPage of width w and height h.
			 'L' Should create a new line from (x1,y1) to (x2,y2). Currently only horizontal or vertical lines are supported. Horizontal and vertical lines will be drawn using the 'x' character.
			 'R' Should create a new rectangle, whose upper left corner is (x1,y1) and lower right corner is (x2,y2). Horizontal and vertical lines will be drawn using the
			 'B' Should fill the entire area connected to (x,y) with colour c. The behavior of this is the same as that of the bucket fill tool in getBuildCanvas  programs.
			 'Q' Should quit the program.
			Your selection please.
			C 20 4
			----------------------
			|                    |
			|                    |
			|                    |
			|                    |
			----------------------
			Your selection please.
			L 1 2 6 2
			----------------------
			|                    |
			|xxxxxx              |
			|                    |
			|                    |
			----------------------
			Your selection please.
			L 6 3 6 4
			----------------------
			|                    |
			|xxxxxx              |
			|     x              |
			|     x              |
			----------------------
			Your selection please.
			R 14 1 18 3
			----------------------
			|             xxxxx  |
			|xxxxxx       x   x  |
			|     x       xxxxx  |
			|     x              |
			----------------------
			Your selection please.
			B 10 3 o
			----------------------
			|oooooooooooooxxxxxoo|
			|xxxxxxooooooox   xoo|
			|     xoooooooxxxxxoo|
			|     xoooooooooooooo|
			----------------------
			Your selection please.
			Q
			Application Quit request is received , App would stop now
			
			



