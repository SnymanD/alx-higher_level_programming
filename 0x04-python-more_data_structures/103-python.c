#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <bytesobject.h>

void print_python_bytes(PyObject *p)
{
	long int size;
	int u;
	char *trying_str;

	trying_str = NULL;


	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	PyBytes_AsStringAndSize(p, &trying_str, &size);

	printf("  size: %li\n", size);
	printf("  trying string: %s\n", trying_str);
	if (size < 10)
		printf("  first %li bytes:", size + 1);
	else
		printf("  first 10 bytes:");
	for (u = 0; u <= size && u < 10; u++)
		printf(" %02hhx", trying_str[u]);
	printf("\n");
}

void print_python_list(PyObject *p)
{
	long int size = PyList_Size(p);
	int u;
	const char *type;
	PyListObject *list = (PyListObject *)p;
	size = PyList_Size(p);

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %li\n", size);
	printf("[*] Allocated = %li\n", list->allocated);
	for (u = 0; u < size; u++)
	{
		type = (list->ob_item[u])->ob_type->tp_name;
		printf("Element %i: %s\n", u, type);
		if (!strcmp(type, "bytes"))
			print_python_bytes(list->ob_item[u]);
	}
}
