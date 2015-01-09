/*********************************************
Broadcast Chatting Project using Contiki OS
Mathieu DELION
Samuel THOMAS
ING5 SE TD2
**********************************************/

#include "contiki.h"
#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *name;

/*---------------------------------------------------------------------------*/
PROCESS(shell_setname_process, "setname");
SHELL_COMMAND(setname_command,
	      "setname", //nom de ma commande
	      "setname : donne un nom ", //affiche dans le help
	      &shell_setname_process);

/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(shell_setname_process, ev, data)
{
  PROCESS_BEGIN();

  	if (data!=NULL && strlen(data)!=0 && name==NULL)
	{
		name=data;
		shell_output_str(&setname_command,"votre nom est : ",name);
	}
	else if (name!=NULL)
	{
		shell_output_str(&setname_command,"votre nom est : ",name);
	}
	else
	{
		shell_output_str(&setname_command, "setname <name> un nom doit etre rentre", "");
	}

  PROCESS_END();
}

void
shell_setname_init(void)
{
	name=NULL;
	shell_register_command(&setname_command);
}
/*---------------------------------------------------------------------------*/
