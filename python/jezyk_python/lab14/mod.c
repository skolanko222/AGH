#include <Python.h>
#include "sort.c"
//mozliwe sygnatury funkcji stanowiącej "interfejs" pomiędzy pythonem i C
//static PyObject *mod_met(PyObject *self){
//static PyObject *mod_met(PyObject *self, PyObject *args, PyObject *kw){
static PyObject *mod_met(PyObject *self, PyObject *args){
	int a,b;
	int c = 0;
	PyObject *d=NULL;
	if(!PyArg_ParseTuple(args, "ii|iO", &a, &b, &c, &d)){ //jezeli do stringa wstawi sie | to po sa parametry opcjonalne; O od Object
		return NULL;	//zwracane w przypadku bledu; interpreter zglasza wyjatek wywolania funkcji
	}
	int s=a+b+c;
	if(d){
		int r=PyList_Size(d);
		for(int i=0; i<r; i++){
			s+=PyLong_AsLong(PyList_GetItem(d,i));
		}
	}
	//Py_RETURN_NONE; //jesli nic nie zwraca
	return Py_BuildValue("i", s);
}

static PyObject *mod_sort(PyObject *self, PyObject *args)
{
	PyObject * py_list = NULL;
	
	long int len_list = 0;

	if(!PyArg_ParseTuple(args, "O", &py_list)){ //jezeli do stringa wstawi sie | to po sa parametry opcjonalne; O od Object
		return NULL;	//zwracane w przypadku bledu; interpreter zglasza wyjatek wywolania funkcji
	}

	len_list = PyList_Size(py_list);

	long int arr[len_list];
	for(int i = 0; i < len_list; i++)
	{
		arr[i] = PyLong_AsLong(PyList_GetItem(py_list,i));
	}
	sort_wstawianie(arr, len_list );
	PyObject * ret = PyList_New(len_list);
	for(int i = 0; i < len_list; i++)
	{
		PyList_SetItem(ret, i,PyLong_FromLong(arr[i]) );
	}
	return ret;


}

static PyObject *mod_nwd(PyObject *self, PyObject *args){

	PyDictObject *dict=NULL;
	if(!PyArg_ParseTuple(args, "O", &dict)){ //jezeli do stringa wstawi sie | to po sa parametry opcjonalne; O od Object
		return NULL;	//zwracane w przypadku bledu; interpreter zglasza wyjatek wywolania funkcji
	}
	int dict_len = PyDict_Size(dict);
	long int keys_arr[dict_len];
	long int vals_arr[dict_len];
	Py_ssize_t pos = 0;
	PyObject *key, *value;
	int i = 0;
	while (PyDict_Next(dict, &pos, &key, &value))
	{
		keys_arr[i] = PyLong_FromLong(key);
		vals_arr[i] = PyLong_FromLong(value);
		i++;

		printf("%d %d \n",keys_arr[i], vals_arr[i]);
	}
	
	return dict;
}

//tablica metod
static PyMethodDef mod_metody[]={
	{"met", (PyCFunction)mod_met, METH_VARARGS, "Funkcja ..."},
	{"sortowanie_c", (PyCFunction)mod_sort, METH_VARARGS, "Funkcja sortujaca przez wstawianie"},
	{"nwd", (PyCFunction)mod_nwd, METH_VARARGS, "Funkcja ..."}, 
	//nazwa funkcja stosowana w Pythonie, adres funkcji , j.w. lub METH_KEYWORDS lub METH_NOARGS, lancuch dokumentacyjny
	{NULL, NULL, 0, NULL}	//wartownik
};


static struct PyModuleDef modmodule={
        PyModuleDef_HEAD_INIT,
        "mod",
        NULL,
        -1,
        mod_metody
};

//funkcja inicjalizujaca
PyMODINIT_FUNC PyInit_mod(void){
        return PyModule_Create(&modmodule);
}
