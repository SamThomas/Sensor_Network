/*********************************************
Broadcast Chatting Project using Contiki OS
Mathieu DELION
Samuel THOMAS
ING5 SE TD2
**********************************************/

#include "contiki.h"
#include "serial-shell.h"
#include "shell.h"
#include "dev/serial-line.h"
#include <stdio.h>

PROCESS(hello_world_process, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process);

PROCESS_THREAD(hello_world_process, ev, data)
{
  PROCESS_BEGIN();
	serial_line_init();
	serial_shell_init();
	shell_reboot_init();
	shell_power_init();
	shell_ps_init();
	shell_ping_init();
	shell_setname_init();

  printf("Hello World Exemple\n");
  Hello_world();

  PROCESS_END();
}
