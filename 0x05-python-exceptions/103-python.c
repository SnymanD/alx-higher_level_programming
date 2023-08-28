/*
 * File: The 103-python.c file
 * Auth: DHLAMINI SNYMAN
 */
#include <Python.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);

/**
 * print_python_list - Returns basic info about Python lists.
 * @p: PyObject 
 */

void print_python_list(PyObject *p)
{
	Py_ssize_t size, alloc, u;
	const char *type;
	PyListObject *list = (PyListObject *)p;
	PyVarObject *var = (PyVarObject *)p;

	size = var->ob_size;
	alloc = list->allocated;

	fflush(stdout);

	printf("[*] Python list info\n");
	if (strcmp(p->ob_type->tp_name, "list") != 0)
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}

	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", alloc);

	for (u = 0; u < size; u++)
	{
		type = list->ob_item[u]->ob_type->tp_name;
		printf("Element %ld: %s\n", u, type);
		if (strcmp(type, "bytes") == 0)
			print_python_bytes(list->ob_item[u]);
		else if (strcmp(type, "float") == 0)
			print_python_float(list->ob_item[u]);
	}
}

/**
 * print_python_bytes - Returns basic info about Python byte objects.
 * @p: A PyObject byte object.
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, u;
	PyBytesObject *bytes = (PyBytesObject *)p;

	fflush(stdout);

	printf("[.] bytes object info\n");
	if (strcmp(p->ob_type->tp_name, "bytes") != 0)
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	printf("  size: %ld\n", ((PyVarObject *)p)->ob_size);
	printf("  trying string: %s\n", bytes->ob_sval);

	if (((PyVarObject *)p)->ob_size >= 10)
		size = 10;
	else
		size = ((PyVarObject *)p)->ob_size + 1;

	printf("  first %ld bytes: ", size);
	for (u = 0; u < size; u++)
	{
		printf("%02hhx", bytes->ob_sval[u]);
		if (u == (size - 1))
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_python_float - Returns basic info about Python float objects.
 * @p: Object
 */
void print_python_float(PyObject *p)
{
	char *buffer = NULL;

	PyFloatObject *float_obj = (PyFloatObject *)p;

	fflush(stdout);

	printf("[.] float object info\n");
	if (strcmp(p->ob_type->tp_name, "float") != 0)
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}

	buffer = PyOS_double_to_string(float_obj->ob_fval, 'r', 0,
			Py_DTSF_ADD_DOT_0, NULL);
	printf("  value: %s\n", buffer);
	PyMem_Free(buffer);
}
