/* a bottle of beer */

#include <mudlib.h>
inherit DRINK;

void reset(status arg) {
  set_name("beer");
  set_empty_container("bottle");
  set_short("bottle of beer");
  set_long("The beer is help in an amber bottle.\n");
  set_weight(1);
  set_value(10);
  set_consumer_msg("It is really good beer!\n");  set_room_msg("@@query_name:$this_player()$@@ drinks a bottle of beer.\n");  set_alco_drink(1);
  set_strength(2);
}
