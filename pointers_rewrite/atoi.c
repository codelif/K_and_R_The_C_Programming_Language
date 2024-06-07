void atoi(char *s, int *n){
  int sign;

  while (*s == ' ')
    s++;

  sign = (*s == '-') ? -1:1;
  if (*s == '-' || *s == '+')
    s++;

  for (*n = 0; (*s >= '0' && *s <= '9'); s++)
    *n = *n * 10 + (*s - '0');
}
