
set da=%date:~8,2%
set /a day=%da%-1

ren *.rar  CR23_Ҷ����_%date:~0,4%.%date:~5,2%.%day%.rar
