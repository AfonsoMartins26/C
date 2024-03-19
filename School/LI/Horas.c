#include <stdio.h>
#include <locale.h>  
#include <wchar.h>

int main()
{
    int hora, min;

    /* Mudar para UTF8 */
    setlocale(LC_CTYPE, "C.UTF-8");
if (scanf("%d%d", &hora, &min) == 2){
  if ((hora == 1 && min == 0) || (hora == 13 && min == 0 )) {
 wchar_t c = 0x1f550;
 wprintf(L"%lc\n", c); 
}
  if ((hora == 2 && min == 0) ||( hora == 14 && min == 0 )) {
 wchar_t c = 0x1f551;
 wprintf(L"%lc\n", c); 
}
  if ((hora == 3 && min == 0)  || (hora == 15 && min == 0)) {
 wchar_t c = 0x1f552;
 wprintf(L"%lc\n", c); 
}
  if ((hora == 4 && min == 0) || (hora == 16 && min == 0 )) {
 wchar_t c = 0x1f553;
 wprintf(L"%lc\n", c); 
}
  if ((hora == 5 && min == 0) ||( hora == 17 && min == 0))  {
 wchar_t c = 0x1f554;
 wprintf(L"%lc\n", c); 
}
  if ((hora == 6 && min == 0) || (hora == 18 && min == 0) ) {
 wchar_t c = 0x1f555;
 wprintf(L"%lc\n", c); 
}
  if ((hora == 7 && min == 0) || (hora == 19 && min == 0 )) {
 wchar_t c = 0x1f556;
 wprintf(L"%lc\n", c); 
}
  if ((hora == 8 && min == 0) || (hora == 20 && min == 0) ) {
 wchar_t c = 0x1f557;
 wprintf(L"%lc\n", c); 
}
  if ((hora == 9 && min == 0) || (hora == 21 && min == 0 )) {
 wchar_t c = 0x1f558;
 wprintf(L"%lc\n", c); 
}
  if ((hora == 10 && min == 0) || (hora == 22 && min == 0 )) {
 wchar_t c = 0x1f559;
 wprintf(L"%lc\n", c); 
}
  if ((hora == 11 && min == 0) || (hora == 23 && min == 0 )) {
 wchar_t c = 0x1f55a;
 wprintf(L"%lc\n", c); 
}
  if ((hora == 12 && min == 0) || (hora == 0 && min == 0 )) {
 wchar_t c = 0x1f55b;
 wprintf(L"%lc\n", c); 
}
  if ((hora == 1 && min == 30 )|| (hora == 13 && min == 30))  {
   wchar_t c = 0x1f55c;
   wprintf(L"%lc\n", c); 
}
  if ((hora == 2 && min == 30 )|| (hora == 14 && min == 30)) {
  wchar_t c = 0x1f55d;
  wprintf(L"%lc\n", c); 
}
  if ((hora == 3 && min == 30) || (hora == 15 && min == 30)) {
  wchar_t c = 0x1f55e;
  wprintf(L"%lc\n", c); 
}
  if ((hora == 4 && min == 30 )|| (hora == 16 && min == 30)) {
  wchar_t c = 0x1f55f;
  wprintf(L"%lc\n", c); 
}
  if ((hora == 5 && min == 30 )|| (hora == 17 && min == 30)) {
  wchar_t c = 0x1f560;
  wprintf(L"%lc\n", c); 
}
  if ((hora == 6 && min == 30 )|| (hora == 18 && min == 30)) {
  wchar_t c = 0x1f561;
  wprintf(L"%lc\n", c); 
}
  if ((hora == 7 && min == 30 )|| (hora == 19 && min == 30)) {
  wchar_t c = 0x1f562;
  wprintf(L"%lc\n", c); 
}
  if ((hora == 8 && min == 30 )|| (hora == 20 && min == 30)) {
  wchar_t c = 0x1f563;
  wprintf(L"%lc\n", c); 
}
  if ((hora == 9 && min == 30 )|| (hora == 21 && min == 30)) {
  wchar_t c = 0x1f564;
  wprintf(L"%lc\n", c); 
}
  if ((hora == 10 && min == 30) || (hora == 22 && min == 30)) {
  wchar_t c = 0x1f565;
  wprintf(L"%lc\n", c); 
}
  if ((hora == 11 && min == 30) || (hora == 23 && min == 30)) {
  wchar_t c = 0x1f566;
  wprintf(L"%lc\n", c); 
}
  if ((hora == 12 && min == 30) || (hora == 0 && min == 30)) {
  wchar_t c = 0x1f567;
  wprintf(L"%lc\n", c); 
}
return 0;
}
}
