#include <Python.h>

PyObject *py_change_string(PyObject *self, PyObject *args){
  PyObject *string, *repstr;
  unsigned long startpos = 0;
  char *byte_place, *repstr_str;
  size_t num_bytes;

  if (PyArg_ParseTuple(args, "OOl", &string, &repstr, &startpos) == 0) {
    return NULL;
  }

  /* number of bytes from string 2 */
  num_bytes = PyString_GET_SIZE(repstr);
  byte_place = PyString_AS_STRING(string);
  repstr_str = PyString_AS_STRING(repstr);

  byte_place = ((char *) ((long) byte_place) + startpos);
  memcpy(byte_place, repstr_str, num_bytes);

  Py_INCREF(Py_None);
  return (Py_None);
}

static PyMethodDef pymutstr_methods[] = {
  {"change_string", py_change_string, METH_VARARGS},
  {NULL, NULL}
};

void
initpymutstr()
{
  (void) Py_InitModule("pymutstr", pymutstr_methods);
}
