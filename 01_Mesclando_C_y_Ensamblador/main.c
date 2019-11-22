void funcion();
char funcion_exit(char);

#ifndef VERSION_JULIO
void main(void)
#else
int main()
#endif
{
  funcion();
#ifndef VERSION_JULIO
  funcion_exit(255);
#else
  return funcion_exit(255);
#endif
}
