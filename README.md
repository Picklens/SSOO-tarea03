# SSOO-tarea03

##### AUTOR: Benjamin Alejandro Leon Gonzalez

##### CORREO: benjamin.leong@alumnos.uv.cl

La solución de este problema se diseño de la siguiente manera:

Señales: se manejaron un numero de señales para que el programa no terminara abruptamente antes de realizar las 50 iteraciones. ej: ctrl+z, ctrl+c, ctrl+\, entre otras. Estas se manejaban a través del signal_handler que le decia al programa lo que debia hacer en caso de recibir una de estas señales.

proceso hijo: se usa la función fork(), con esta funcion se le asigna una variable pid que tiene valor 0 para el proceso hijo (numero impar), y usamos un else para la padre(fibonacci). ademas se usa un sleep de medio segundo para poder ver los numeros
