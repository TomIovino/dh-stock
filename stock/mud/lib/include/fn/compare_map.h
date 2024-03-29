#ifndef COMPARE_H
#define COMPARE_H

/***************************************************************************/
/* compare two skills */

object *compare(string my_skill, string their_skill, object *compare) { 
  if(!my_skill || !their_skill) return ({}); 
  if(!compare) compare = all_inventory(environment());
  return filter_array(compare,"comp",this_object(),({my_skill,their_skill,}));
}

static status comp(object ob, string *skills) {
  int my_skill, their_skill;

  if(!ob || ob == this_player()) return 0;
  my_skill = (int)call_other(this_player(),
               "query_stat("+skills[0]+")") + 1; 
  their_skill = (int)call_other(ob, "query_stat("+skills[1]+")") + 1;
  if(my_skill < their_skill) return 1;
  return 0;
} 

#endif /* end COMPARE_H */
