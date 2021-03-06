#Disallow in source builds everywhere
if(
	"${CMAKE_BINARY_DIR}"
	STREQUAL
	"${CMAKE_SOURCE_DIR}"
)
	message(
		FATAL_ERROR
		"In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files that cmake just created:\nrm -rf CMakeCache.txt CMakeFiles"
	)
endif()

include(
	CMakeDetermineCXXCompiler
)

include(
	CheckCXXCompilerFlag
)

include(
	CMakeParseArguments
)

# Define locations for installations
# These don't have an FCPPT_ prefix because they have to be set by the user

set(
	INSTALL_BINARY_DIR
	"${CMAKE_INSTALL_PREFIX}/bin"
	CACHE
	STRING
	"Custom binary installation directory"
)

# Some distributions set CMAKE_INSTALL_LIBDIR to handle multilib. Also, some of
# them use an absolute path, some use a relative path. We have chosen an
# absolute path here, so please change it in the build if your distribution is
# using relative paths.
if(
	DEFINED
	CMAKE_INSTALL_LIBDIR
)
	set(
		FCPPT_UTILS_DEFAULT_INSTALL_LIB_DIR
		"${CMAKE_INSTALL_LIBDIR}"
	)
else()
	set(
		FCPPT_UTILS_DEFAULT_INSTALL_LIB_DIR
		"${CMAKE_INSTALL_PREFIX}/lib"
	)
endif()

set(
	INSTALL_LIBRARY_DIR
	"${FCPPT_UTILS_DEFAULT_INSTALL_LIB_DIR}"
	CACHE
	STRING
	"Custom library installation directory"
)

set(
	INSTALL_INCLUDE_DIR
	"${CMAKE_INSTALL_PREFIX}/include"
	CACHE
	STRING
	"Custom include installation directory"
)

set(
	INSTALL_DATA_DIR_BASE
	"${CMAKE_INSTALL_PREFIX}/share"
	CACHE
	STRING
	"Custom data installation directory without suffixes"
)

function(
	fcppt_utils_install_data_dir
	VAR_NAME
)
	set(
		${VAR_NAME}
		"${INSTALL_DATA_DIR_BASE}/${PROJECT_NAME}"
		PARENT_SCOPE
	)
endfunction()

set(
	INSTALL_DOC_DIR_BASE
	"${INSTALL_DATA_DIR_BASE}/doc"
	CACHE
	STRING
	"Custom doc installation directory without suffixes"
)

function(
	fcppt_utils_install_doc_dir
	VAR_NAME
)
	set(
		${VAR_NAME}
		"${INSTALL_DOC_DIR_BASE}/${PROJECT_NAME}"
		PARENT_SCOPE
	)
endfunction()

set(
	INSTALL_PKGCONFIG_DIR
	"${INSTALL_LIBRARY_DIR}/pkgconfig"
	CACHE
	STRING
	"Custom pkgconfig installation directory"
)

set(
	FCPPT_UTILS_CURRENT_DIRECTORY
	"${CMAKE_ROOT}"
)

set(
	FCPPT_UTILS_PROJECT_SOURCE_DIR
	"${${PROJECT_NAME}_SOURCE_DIR}"
)

set(
	FCPPT_UTILS_PROJECT_BINARY_DIR
	"${${PROJECT_NAME}_BINARY_DIR}"
)

function(
	fcppt_utils_is_path_prefix_of
	RESULT
	PREFIX_STRING
	PATH_STRING
)
	set(
		${RESULT}
		FALSE
		PARENT_SCOPE
	)

	set(
		CURRENT_DIRECTORY
		"${PATH_STRING}"
	)

	while(
		TRUE
	)
		if(
			"${PREFIX_STRING}"
			STREQUAL "${CURRENT_DIRECTORY}"
		)
			set(
				${RESULT}
				TRUE
				PARENT_SCOPE
			)

			break()
		endif()

		get_filename_component(
			NEW_CURRENT_DIRECTORY
			"${CURRENT_DIRECTORY}"
			PATH
		)

		if(
			"${NEW_CURRENT_DIRECTORY}"
			STREQUAL
			"${CURRENT_DIRECTORY}"
		)
			break()
		endif()

		set(
			CURRENT_DIRECTORY
			"${NEW_CURRENT_DIRECTORY}"
		)
	endwhile()
endfunction()

fcppt_utils_is_path_prefix_of(
	FCPPT_UTILS_INSTALL_PREFIX_IS_PREFIX_OF_CMAKE_ROOT
	"${CMAKE_INSTALL_PREFIX}"
	"${CMAKE_ROOT}"
)

if(
	FCPPT_UTILS_INSTALL_PREFIX_IS_PREFIX_OF_CMAKE_ROOT
)
	set(
		FCPPT_UTILS_CMAKE_MODULE_DIR
		"${CMAKE_ROOT}/Modules"
	)
else()
	set(
		FCPPT_UTILS_CMAKE_MODULE_DIR
		"${INSTALL_DATA_DIR_BASE}/cmake/Modules"
	)
endif()

set(
	INSTALL_CMAKEMODULES_DIR
	"${FCPPT_UTILS_CMAKE_MODULE_DIR}"
	CACHE
	STRING
	"Custom cmake module installation directory"
)

set(
	INSTALL_CMAKECONFIG_DIR_BASE
	"${INSTALL_LIBRARY_DIR}/cmake"
	CACHE
	STRING
	"Custom cmake config installation directory without suffixes"
)

function(
	fcppt_utils_install_cmakeconfig_dir
	VAR_NAME
)
	set(
		${VAR_NAME}
		"${INSTALL_CMAKECONFIG_DIR_BASE}/${PROJECT_NAME}"
		PARENT_SCOPE
	)
endfunction()

set(
	INSTALL_SYSCONFIG_DIR_BASE
	"${CMAKE_INSTALL_PREFIX}/etc"
	CACHE
	STRING
	"Custom config installation directory"
)

if(
	${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang"
	OR
	${CMAKE_CXX_COMPILER_ID} STREQUAL "AppleClang"
)
	set(
		FCPPT_UTILS_COMPILER_IS_CLANGPP
		ON
	)
endif()

if(
	${CMAKE_CXX_COMPILER_ID} STREQUAL "Intel"
)
	set(
		FCPPT_UTILS_COMPILER_IS_INTELCPP
		ON
	)
endif()

# Setup default compiler flags

if(
	CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP
)
	set(
		CMAKE_CXX_FLAGS_RELEASE
		"-O3 -fomit-frame-pointer -DNDEBUG"
	)

	# cmake tries to grep for warning messages which will fail in a lot of cases
	set(
		CMAKE_REQUIRED_FLAGS_BASE
		"-Wall -Werror -pedantic"
	)

	set(
		CMAKE_REQUIRED_FLAGS
		${CMAKE_REQUIRED_FLAGS_BASE}
	)

	CHECK_CXX_COMPILER_FLAG(
		"-fvisibility=hidden"
		FCPPT_UTILS_HAVE_GCC_VISIBILITY
	)

	list(
		APPEND
		FCPPT_UTILS_COMPILE_OPTIONS
		"-std=c++14"
		"-pedantic"
		"-pedantic-errors"
		"-Wall"
		"-Wextra"
		"-Wcast-align"
		"-Wcast-qual"
		"-Wconversion"
		"-Wconversion-null"
		"-Wdelete-non-virtual-dtor"
		"-Weffc++"
		"-Wfloat-equal"
		"-Winit-self"
		"-Wmissing-declarations"
		"-Wnon-virtual-dtor"
		"-Wold-style-cast"
		"-Woverloaded-virtual"
		"-Wredundant-decls"
		"-Wsign-promo"
		"-Wsign-conversion"
		"-Wshadow"
		"-Wstrict-aliasing=1"
		"-Wuninitialized"
		"-Wunused"
		"-Wunused-function"
		#currently, -Wundef cannot be disabled via a pragma
	)

	if(
		FCPPT_UTILS_COMPILER_IS_CLANGPP
	)
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-Wconditional-uninitialized"
			"-Wdocumentation"
			"-Wextra-semi"
			"-Wimplicit-fallthrough"
			"-Wundef"
			"-Wunneeded-member-function"
			"-Wunused-member-function"
		)
	else()
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-Wdouble-promotion"
			"-Wlogical-op"
			"-Wmaybe-uninitialized"
			"-Wmissing-include-dirs"
			"-Wsuggest-override"
			"-Wunused-local-typedefs"
		)

		#"-Wzero-as-null-pointer-constant" - too many warnings from boost that cannot be disabled

		if(
			CMAKE_CXX_COMPILER_VERSION
			VERSION_GREATER
			6.0
		)
			list(
				APPEND
				FCPPT_UTILS_COMPILE_OPTIONS
				"-Wduplicated-cond"
				"-Wnull-dereference"
			)
		endif()
	endif()

	if(
		FCPPT_UTILS_HAVE_GCC_VISIBILITY
	)
		option(
			FCPPT_ENABLE_VISIBILITY_HIDDEN
			"Enable -fvisbility=hidden"
			TRUE
		)
	endif()

	if(
		FCPPT_ENABLE_VISIBILITY_HIDDEN
	)
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-fvisibility=hidden"
		)
	endif()
elseif(
	MSVC
)
	list(
		APPEND
		FCPPT_UTILS_COMPILE_OPTIONS
		/W4
		/Wall
		/EHa
		/D_BIND_TO_CURRENT_VCLIBS_VERSION=1
		/wd4435
		/wd4996
		/wd4061
		/wd4350
		/wd4371
		/wd4503
		/wd4514
		/wd4710
		/wd4711
		/wd4714
		/wd4738
		/wd4820
		/wd4868
		/wd5031
	)

	# /W4 warnings
	#4996 - unsafe standard C++ functions

	# /Wall warnings
	#4061 - warning for not handled cases in switchs even with default
	#4350 - behaviour change due to implicit conversions (needed for unique_ptr)
	#4371 - layout of class may have changed from previous compiler version
	#4435 - layout change because of virtual base class
	#4503 - decorated name length exceeded
	#4514 - unreferenced inline function removed
	#4710 - function not inlined
	#4711 - function selected for automatic inline expansion
	#4714 - function marked as __forceinline not inlined
	#4738 - storing 32-bit float result in memory
	#4820 - byte padding after data members
	#4868 - compiler may not enforce left-to-right evaluation order in braced initializer list
	#5031 - warning(pop) in different file
endif()

# setup platform specific flags
if(
	UNIX
)
	# we need -fPIC for libraries on AMD64
	if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64")
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-fPIC"
		)
	endif()

	# To check for linker flags, CMAKE_REQUIRED_FLAGS has to be expanded
	function(
		fcppt_check_gcc_linker_flag
		FLAG
		VARIABLE
	)
		set(
			CMAKE_REQUIRED_FLAGS
			"${CMAKE_REQUIRED_FLAGS_BASE} ${FLAG}"
		)

		CHECK_CXX_COMPILER_FLAG(
			""
			${VARIABLE}
		)
	endfunction()

	fcppt_check_gcc_linker_flag(
		"-Wl,--as-needed"
		FCPPT_UTILS_HAVE_AS_NEEDED_LINKER_FLAG
	)

	fcppt_check_gcc_linker_flag(
		"-Wl,--no-undefined"
		FCPPT_UTILS_HAVE_NO_UNDEFINED_LINKER_FLAG
	)

	fcppt_check_gcc_linker_flag(
		"-Wl,--no-copy-dt-needed-entries"
		FCPPT_UTILS_HAVE_NO_COPY_DT_NEEDED_ENTRIES_LINKER_FLAG
	)

	if(
		FCPPT_UTILS_HAVE_AS_NEEDED_LINKER_FLAG
	)
		set(
			FCPPT_UTILS_SHARED_LINKER_FLAGS
			"-Wl,--as-needed ${FCPPT_UTILS_SHARED_LINKER_FLAGS}"
		)
	endif()

	if(
		FCPPT_UTILS_HAVE_NO_UNDEFINED_LINKER_FLAG
	)
		set(
			FCPPT_UTILS_SHARED_LINKER_FLAGS
			"-Wl,--no-undefined ${FCPPT_UTILS_SHARED_LINKER_FLAGS}"
		)
	endif()

	if(
		FCPPT_UTILS_HAVE_NO_COPY_DT_NEEDED_ENTRIES_LINKER_FLAG
	)
		set(
			FCPPT_UTILS_SHARED_LINKER_FLAGS
			"-Wl,--no-copy-dt-needed-entries ${FCPPT_UTILS_SHARED_LINKER_FLAGS}"
		)
		set(
			FCPPT_UTILS_EXE_LINKER_FLAGS
			"-Wl,--no-copy-dt-needed-entries ${FCPPT_UTILS_EXE_LINKER_FLAGS}"
		)
	endif()
endif()

# Ignore Boost's deprecated features
set(
	FCPPT_UTILS_COMPILE_DEFINITIONS
	"BOOST_FILESYSTEM_NO_DEPRECATED"
	"BOOST_SYSTEM_NO_DEPRECATED"
)

# configure standard CMake build paths
set(
	CMAKE_RUNTIME_OUTPUT_DIRECTORY
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/bin
)

set(
	CMAKE_LIBRARY_OUTPUT_DIRECTORY
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/lib
)

set(
	CMAKE_ARCHIVE_OUTPUT_DIRECTORY
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/lib
)

option(
	FCPPT_UTILS_BUILD_HEADERS
	"Build header files as well. This is useful for compile_commands.json. Don't use it to do an actual build."
	FALSE
)

function(
	fcppt_utils_add_headers
	ALL_FILES
)
	foreach(
		CUR_FILE
		${ALL_FILES}
	)
		get_filename_component(
			CUR_EXT
			"${CUR_FILE}"
			EXT
		)

		if(
			"${CUR_EXT}"
			STREQUAL
			".hpp"
		)
			set(
				LANGUAGE
				"CXX"
			)
		elseif(
			"${CUR_EXT}"
			STREQUAL
			".h"
		)
			set(
				LANGUAGE
				"C"
			)
		endif()

		if(
			DEFINED LANGUAGE
		)
			set_source_files_properties(
				"${CUR_FILE}"
				PROPERTIES
				LANGUAGE
				${LANGUAGE}
			)
		endif()
	endforeach()
endfunction()

function(
	fcppt_utils_add_source_groups
	ALL_FILES
)
	foreach(
		CURFILE
		${ALL_FILES}
	)
		get_filename_component(
			REL_PATH
			"${CURFILE}"
			PATH
		)

		string(
			REPLACE
			"/"
			"\\"
			GROUPFOLDER
			${REL_PATH}
		)

		source_group(
			${GROUPFOLDER}
			FILES
			${CURFILE}
		)
	endforeach()

	if(
		FCPPT_UTILS_BUILD_HEADERS
	)
		fcppt_utils_add_headers(
			"${ALL_FILES}"
		)
	endif()
endfunction()

function(
	fcppt_utils_append_source_dir
	FILES
	RESULT
)
	foreach(
		CUR_FILE
		${FILES}
	)
		set(
			WHOLE_FILE
			${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${CUR_FILE}
		)

		list(
			APPEND
			${RESULT}
			${WHOLE_FILE}
		)
	endforeach()

	set(
		${RESULT}
		${${RESULT}}
		PARENT_SCOPE
	)
endfunction()

function(
	fcppt_utils_append_source_dir_and_make_groups
	FILES
	RESULT
)
	foreach(
		CUR_FILE
		${FILES}
	)
		set(
			WHOLE_FILE
			${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${CUR_FILE}
		)

		get_filename_component(
			REL_PATH
			${CUR_FILE}
			PATH
		)

		string(
			REPLACE
			"/"
			"\\"
			GROUPFOLDER
			${REL_PATH}
		)

		source_group(
			${GROUPFOLDER}
			FILES
			${WHOLE_FILE}
		)

		list(
			APPEND
			TEMP_RESULT
			${WHOLE_FILE}
		)
	endforeach()

	set(
		${RESULT}
		"${TEMP_RESULT}"
		PARENT_SCOPE
	)

	if(
		FCPPT_UTILS_BUILD_HEADERS
	)
		fcppt_utils_add_headers(
			"${TEMP_RESULT}"
		)
	endif()
endfunction()

set(
	FCPPT_UTILS_TARGETS_CONFIG
	"${PROJECT_NAME}Targets.cmake"
)

set(
	FCPPT_UTILS_BUILD_CONFIG_DIR
	"${FCPPT_UTILS_PROJECT_BINARY_DIR}/config"
)

set(
	FCPPT_UTILS_BUILD_CONFIG
	"${FCPPT_UTILS_BUILD_CONFIG_DIR}/${FCPPT_UTILS_TARGETS_CONFIG}"
)

set(
	FCPPT_UTILS_EXPORT_NAME
	"${PROJECT_NAME}Export"
)

function(
	fcppt_utils_export_install_target
	TARGETNAME
)
	install(
		TARGETS
		${TARGETNAME}
		DESTINATION
		"${INSTALL_LIBRARY_DIR}"
		EXPORT
		"${FCPPT_UTILS_EXPORT_NAME}"
	)
endfunction()

set(
	FCPPT_UTILS_SOURCE_INCLUDE_DIR
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include
)

set(
	FCPPT_UTILS_BINARY_INCLUDE_DIR
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/include
)

function(
	fcppt_utils_generate_config
)
	set(
		SINGLE_ARGS
		CONFIG_PATH
	)

	cmake_parse_arguments(
		""
		""
		"${SINGLE_ARGS}"
		""
		${ARGN}
	)

	if(
		NOT
		"${_UNPARSED_ARGUMENTS}"
		STREQUAL
		""
	)
		message(
			FATAL_ERROR
			"Invalid parameters ${_UNPARSED_ARGUMENTS}"
		)
	endif()

	fcppt_utils_install_cmakeconfig_dir(
		INSTALL_CMAKECONFIG_DIR
	)

	set(
		CONFIG_NAME
		"${PROJECT_NAME}-config.cmake"
	)

	if(
		"${_CONFIG_PATH}"
		STREQUAL
		""
	)
		set(
			CONFIG_FILE_PATH
			${FCPPT_UTILS_PROJECT_SOURCE_DIR}
		)
	else()
		set(
			CONFIG_FILE_PATH
			${_CONFIG_PATH}
		)
	endif()

	set(
		CONFIG_IN_FILE
		"${CONFIG_FILE_PATH}/${CONFIG_NAME}.in"
	)

	set(
		CONFIG_DEST
		"${FCPPT_UTILS_BUILD_CONFIG_DIR}/${CONFIG_NAME}"
	)

	configure_file(
		${CONFIG_IN_FILE}
		${CONFIG_DEST}
		@ONLY
	)

	install(
		FILES
		"${CONFIG_DEST}"
		DESTINATION
		"${INSTALL_CMAKECONFIG_DIR}"
	)

	export(
		EXPORT
		"${FCPPT_UTILS_EXPORT_NAME}"
		FILE
		"${FCPPT_UTILS_BUILD_CONFIG}"
	)

	install(
		EXPORT
		"${FCPPT_UTILS_EXPORT_NAME}"
		FILE
		"${FCPPT_UTILS_TARGETS_CONFIG}"
		DESTINATION
		"${INSTALL_CMAKECONFIG_DIR}"
	)
endfunction()

function(
	fcppt_utils_handle_so_version
	CACHE_VAR
	OUT_VAR
	DEFAULT_VERSION
)
	set(
		"${CACHE_VAR}"
		""
		CACHE
		STRING
		"The custom .so version to use. If empty, the default will be used."
	)

	if(
		"${${CACHE_VAR}}"
		STREQUAL
		""
	)
		set(
			"${OUT_VAR}"
			"${DEFAULT_VERSION}"
			PARENT_SCOPE
		)
	else()
		set(
			"${OUT_VAR}"
			"${${CACHE_VAR}}"
			PARENT_SCOPE
		)
	endif()
endfunction()

function(
	fcppt_utils_set_so_version
	TARGET
	VERSION
)
	set_target_properties(
		${TARGET}
		PROPERTIES
		VERSION
		${VERSION}
	)
endfunction()

function(
	fcppt_utils_add_dummy_target
	TARGET_NAME
	TARGET_FILES
)
	set(
		MULTI_ARGS
		INCLUDE_DIRS
		LINK_LIBS
	)

	cmake_parse_arguments(
		""
		""
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	if(
		NOT
		"${_UNPARSED_ARGUMENTS}"
		STREQUAL
		""
	)
		message(
			FATAL_ERROR
			"Invalid parameters ${_UNPARSED_ARGUMENTS}"
		)
	endif()


	set(
		LIBNAME
		"${TARGET_NAME}_dummy"
	)

	add_library(
		"${LIBNAME}"
		STATIC
		${TARGET_FILES}
	)

	set_target_properties(
		"${LIBNAME}"
		PROPERTIES
		LINKER_LANGUAGE
		"CXX"
	)

	target_include_directories(
		${LIBNAME}
		PRIVATE
		${_INCLUDE_DIRS}
	)

	target_link_libraries(
		${LIBNAME}
		PRIVATE
		${_LINK_LIBS}
	)
endfunction()

function(
	fcppt_utils_set_target_compiler_flags
	TARGET_NAME
)
	set(
		MULTI_ARGS
		ADDITIONAL_FLAGS
	)

	cmake_parse_arguments(
		""
		""
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	target_compile_definitions(
		${TARGET_NAME}
		PRIVATE
		${FCPPT_UTILS_COMPILE_DEFINITIONS}
	)

	set(
		COMPILE_OPTIONS
		${FCPPT_UTILS_COMPILE_OPTIONS}
		${_ADDITIONAL_FLAGS}
	)

	set_target_properties(
		${TARGET_NAME}
		PROPERTIES
		COMPILE_OPTIONS
		"${COMPILE_OPTIONS}"
		NO_SYSTEM_FROM_IMPORTED
		TRUE
	)

	get_target_property(
		TARGET_TYPE
		${TARGET_NAME}
		TYPE
	)

	get_target_property(
		TEMP_LINK_FLAGS
		${TARGET_NAME}
		LINK_FLAGS
	)

	if(
		TEMP_LINK_FLAGS
		STREQUAL
		"TEMP_LINK_FLAGS-NOTFOUND"
	)
		unset(
			TEMP_LINK_FLAGS
		)
	endif()

	if(
		${TARGET_TYPE}
		STREQUAL
		"SHARED_LIBRARY"
	)
		set(
			TEMP_LINK_FLAGS
			"${FCPPT_UTILS_SHARED_LINKER_FLAGS} ${OLD_LINK_FLAGS}"
		)
	endif()

	if(
		${TARGET_TYPE}
		STREQUAL
		"EXECUTABLE"
	)
		set(
			TEMP_LINK_FLAGS
			"${FCPPT_UTILS_EXE_LINKER_FLAGS} ${OLD_LINK_FLAGS}"
		)
	endif()

	set_target_properties(
		${TARGET_NAME}
		PROPERTIES
		LINK_FLAGS
		"${TEMP_LINK_FLAGS}"
	)
endfunction()

function(
	fcppt_utils_static_shared
)
	option(
		ENABLE_SHARED
		"Build shared libraries"
		ON
	)

	option(
		ENABLE_STATIC
		"Build static libraries"
		OFF
	)

	if(
		NOT ENABLE_SHARED AND NOT ENABLE_STATIC
	)
		message(
			FATAL_ERROR
			"You disabled both STATIC and SHARED"
		)
	endif()

	if(
		ENABLE_STATIC
	)
		set(
			FCPPT_UTILS_DEFAULT_LINK_STATIC
			TRUE
			PARENT_SCOPE
		)
	endif()

	# shared overrides static
	if(
		ENABLE_SHARED
	)
		set(
			FCPPT_UTILS_DEFAULT_LINK_STATIC
			FALSE
			PARENT_SCOPE
		)
	endif()
endfunction()

function(
	fcppt_utils_static_link_name
	LIBNAME
	RESULT
)
	set(
		${RESULT}
		${LIBNAME}_static
		PARENT_SCOPE
	)
endfunction()

function(
	fcppt_utils_interface_link_name
	LIBNAME
	RESULT
)
	set(
		${RESULT}
		${LIBNAME}_interface
		PARENT_SCOPE
	)
endfunction()

function(
	fcppt_utils_link_target
	LIBNAME
)
	set(
		TARGET_NAME
		${LIBNAME}_TARGET
	)

	if(
		FCPPT_UTILS_DEFAULT_LINK_STATIC
	)
		fcppt_utils_static_link_name(
			${LIBNAME}
			STATIC_NAME
		)

		set(
			${TARGET_NAME}
			${STATIC_NAME}
			PARENT_SCOPE
		)
	else()
		set(
			${TARGET_NAME}
			${LIBNAME}
			PARENT_SCOPE
		)
	endif()
endfunction()


function(
	fcppt_utils_interface_static_link
	TARGET_NAME
	VARIANT
	LINK_FLAG
)
	if(
		${VARIANT} STREQUAL "STATIC"
	)
		target_compile_definitions(
			${TARGET_NAME}
			PUBLIC
			${LINK_FLAG}
		)
	endif()
endfunction()

function(
	fcppt_utils_set_target_folder
	TARGET_NAME
	PREFIX
	PATH_NAME
)
	string(
		FIND
		${PATH_NAME}
		"/"
		LAST_PART
		REVERSE
	)

	if(
		NOT
		LAST_PART
		EQUAL
		-1
	)
		string(
			SUBSTRING
			${PATH_NAME}
			0
			${LAST_PART}
			FOLDER_NAME
		)

		set(
			FOLDER_NAME
			"/${FOLDER_NAME}"
		)
	endif()

	set_target_properties(
		${TARGET_NAME}
		PROPERTIES
		FOLDER
		${PROJECT_NAME}/${PREFIX}${FOLDER_NAME}
	)
endfunction()

function(
	fcppt_utils_add_test
	TEST_DIR
	PATH_NAME
)
	set(
		OPTION_ARGS
		NO_CODE
	)

	set(
		MULTI_ARGS
		LINK_LIBS
		INCLUDE_DIRS
	)

	cmake_parse_arguments(
		""
		"${OPTION_ARGS}"
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	string(
		REPLACE
		"/"
		"_"
		TEST_NAME
		${PATH_NAME}
	)

	set(
		FULL_TEST_NAME
		${PROJECT_NAME}_test_${TEST_NAME}
	)

	add_executable(
		${FULL_TEST_NAME}
		${TEST_DIR}/${PATH_NAME}.cpp
	)

	fcppt_utils_set_target_folder(
		${FULL_TEST_NAME}
		tests
		${PATH_NAME}
	)

	fcppt_utils_set_target_compiler_flags(
		${FULL_TEST_NAME}
	)

	target_include_directories(
		${FULL_TEST_NAME}
		PRIVATE
		${_INCLUDE_DIRS}
		${Boost_INCLUDE_DIRS}
	)

	target_link_libraries(
		${FULL_TEST_NAME}
		PRIVATE
		${_LINK_LIBS}
	)

	if(
		NOT ${_NO_CODE}
	)
		target_compile_definitions(
			${FULL_TEST_NAME}
			PRIVATE
			BOOST_TEST_MODULE=${TEST_NAME}
		)

		if(
			Boost_USE_STATIC_LIBS
		)
			target_compile_definitions(
				${FULL_TEST_NAME}
				PRIVATE
				BOOST_TEST_NO_LIB
			)
		else()
			target_compile_definitions(
				${FULL_TEST_NAME}
				PRIVATE
				BOOST_TEST_DYN_LINK
			)
		endif()

		target_link_libraries(
			${FULL_TEST_NAME}
			PRIVATE
			${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
		)

		add_test(
			NAME
			${TEST_NAME}
			COMMAND
			${FULL_TEST_NAME}
		)
	endif()
endfunction()

function(
	fcppt_utils_add_example
	EXAMPLE_DIR
	PATH_NAME
)
	set(
		OPTION_ARGS
		IS_C
	)

	set(
		MULTI_ARGS
		LINK_LIBS
		INCLUDE_DIRS
		COMPILE_DEFINITIONS
	)

	cmake_parse_arguments(
		""
		"${OPTION_ARGS}"
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	string(
		REPLACE
		"/"
		"_"
		EXAMPLE_NAME
		${PATH_NAME}
	)

	set(
		FULL_EXAMPLE_NAME
		${PROJECT_NAME}_example_${EXAMPLE_NAME}
	)

	if(
		${_IS_C}
	)
		set(
			SUFFIX
			"c"
		)
	else()
		set(
			SUFFIX
			"cpp"
		)
	endif()

	add_executable(
		${FULL_EXAMPLE_NAME}
		${EXAMPLE_DIR}/${PATH_NAME}.${SUFFIX}
	)

	fcppt_utils_set_target_folder(
		${FULL_EXAMPLE_NAME}
		examples
		${PATH_NAME}
	)

	target_compile_definitions(
		${FULL_EXAMPLE_NAME}
		PRIVATE
		"${_COMPILE_DEFINITIONS}"
	)

	target_include_directories(
		${FULL_EXAMPLE_NAME}
		PRIVATE
		${_INCLUDE_DIRS}
	)

	if(
		NOT _IS_C
	)
		fcppt_utils_set_target_compiler_flags(
			${FULL_EXAMPLE_NAME}
		)
	endif()

	target_link_libraries(
		${FULL_EXAMPLE_NAME}
		PRIVATE
		${_LINK_LIBS}
	)
endfunction()
