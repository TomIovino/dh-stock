#include "exec.h" /* for size of struct instr */

#define F_OFFSET F_ILLEGAL
#define LAST_INSTRUCTION_CODE 515

extern struct instr instrs[518];
extern short efun_aliases[2];

#define F_ADD_ACTION (F_OFFSET+103)
#define F_ALL_INVENTORY (F_OFFSET+104)
#define F_ALLOCATE (F_OFFSET+105)
#define F_APPLY (F_OFFSET+106)
#define F_ASSOC (F_OFFSET+107)
#define F_BIND_LAMBDA (F_OFFSET+108)
#define F_BREAK_POINT (F_OFFSET+109)
#define F_CALL_OTHER (F_OFFSET+110)
#define F_CALL_OUT (F_OFFSET+111)
#define F_CALL_OUT_INFO (F_OFFSET+112)
#define F_CAPITALIZE (F_OFFSET+113)
#define F_CAT (F_OFFSET+114)
#define F_CLEAR_BIT (F_OFFSET+115)
#define F_CLONE_OBJECT (F_OFFSET+116)
#define F_CLOSUREP (F_OFFSET+117)
#define F_COMMAND (F_OFFSET+118)
#define F_CREATOR (F_OFFSET+119)
#define F_CRYPT (F_OFFSET+120)
#define F_CTIME (F_OFFSET+121)
#define F_DEEP_INVENTORY (F_OFFSET+122)
#define F_DESTRUCT (F_OFFSET+123)
#define F_DISABLE_COMMANDS (F_OFFSET+124)
#define F_ED (F_OFFSET+125)
#define F_ENABLE_COMMANDS (F_OFFSET+126)
#define F_ENVIRONMENT (F_OFFSET+127)
#define F_EXEC (F_OFFSET+128)
#define F_EXPLODE (F_OFFSET+129)
#define F_FILE_NAME (F_OFFSET+130)
#define F_FILE_SIZE (F_OFFSET+131)
#define F_FILTER_ARRAY (F_OFFSET+132)
#define F_FILTER_MAPPING (F_OFFSET+133)
#define F_FIND_CALL_OUT (F_OFFSET+134)
#define F_FIND_OBJECT (F_OFFSET+135)
#define F_FIRST_INVENTORY (F_OFFSET+136)
#define F_FLOATP (F_OFFSET+137)
#define F_FUNCALL (F_OFFSET+138)
#define F_FUNCTION_EXISTS (F_OFFSET+139)
#define F_GET_DIR (F_OFFSET+140)
#define F_IMPLODE (F_OFFSET+141)
#define F_INPUT_TO (F_OFFSET+142)
#define F_INSERT_ALIST (F_OFFSET+143)
#define F_INTERACTIVE (F_OFFSET+144)
#define F_INTERSECT_ALIST (F_OFFSET+145)
#define F_INTP (F_OFFSET+146)
#define F_LAMBDA (F_OFFSET+147)
#define F_LIVING (F_OFFSET+148)
#define F_LOWER_CASE (F_OFFSET+149)
#define F_M_DELETE (F_OFFSET+150)
#define F_M_INDICES (F_OFFSET+151)
#define F_M_VALUES (F_OFFSET+152)
#define F_MAP_ARRAY (F_OFFSET+153)
#define F_MAP_MAPPING (F_OFFSET+154)
#define F_MAPPINGP (F_OFFSET+155)
#define F_MEMBER (F_OFFSET+156)
#define F_MEMBER_ARRAY (F_OFFSET+157)
#define F_MKDIR (F_OFFSET+158)
#define F_MKMAPPING (F_OFFSET+159)
#define F_MOVE_OBJECT (F_OFFSET+160)
#define F_NEGATE (F_OFFSET+161)
#define F_NEXT_INVENTORY (F_OFFSET+162)
#define F_NOTIFY_FAIL (F_OFFSET+163)
#define F_OBJECTP (F_OFFSET+164)
#define F_ORDER_ALIST (F_OFFSET+165)
#define F_POINTERP (F_OFFSET+166)
#define F_PRESENT (F_OFFSET+167)
#define F_PRINTF (F_OFFSET+168)
#define F_PROCESS_STRING (F_OFFSET+169)
#define F_QUERY_ACTIONS (F_OFFSET+170)
#define F_QUERY_LOAD_AVERAGE (F_OFFSET+171)
#define F_QUERY_VERB (F_OFFSET+172)
#define F_QUOTE (F_OFFSET+173)
#define F_RANDOM (F_OFFSET+174)
#define F_READ_BYTES (F_OFFSET+175)
#define F_READ_FILE (F_OFFSET+176)
#define F_REGEXP (F_OFFSET+177)
#define F_REMOVE_CALL_OUT (F_OFFSET+178)
#define F_RENAME (F_OFFSET+179)
#define F_REPLACE_PROGRAM (F_OFFSET+180)
#define F_RESTORE_OBJECT (F_OFFSET+181)
#define F_RM (F_OFFSET+182)
#define F_RMDIR (F_OFFSET+183)
#define F_RUSAGE (F_OFFSET+184)
#define F_SAVE_OBJECT (F_OFFSET+185)
#define F_SAY (F_OFFSET+186)
#define F_SET_BIT (F_OFFSET+187)
#define F_SET_HEART_BEAT (F_OFFSET+188)
#define F_SET_LIGHT (F_OFFSET+189)
#define F_SET_THIS_OBJECT (F_OFFSET+190)
#define F_SIZEOF (F_OFFSET+191)
#define F_SNOOP (F_OFFSET+192)
#define F_SORT_ARRAY (F_OFFSET+193)
#define F_SPRINTF (F_OFFSET+194)
#define F_STRINGP (F_OFFSET+195)
#define F_STRLEN (F_OFFSET+196)
#define F_SYMBOL_FUNCTION (F_OFFSET+197)
#define F_SYMBOLP (F_OFFSET+198)
#define F_TAIL (F_OFFSET+199)
#define F_TELL_OBJECT (F_OFFSET+200)
#define F_TELL_ROOM (F_OFFSET+201)
#define F_TEST_BIT (F_OFFSET+202)
#define F_THIS_INTERACTIVE (F_OFFSET+203)
#define F_THIS_OBJECT (F_OFFSET+204)
#define F_THIS_PLAYER (F_OFFSET+205)
#define F_THROW (F_OFFSET+206)
#define F_TIME (F_OFFSET+207)
#define F_TRANSFER (F_OFFSET+208)
#define F_UNIQUE_ARRAY (F_OFFSET+209)
#define F_USERS (F_OFFSET+210)
#define F_WRITE (F_OFFSET+211)
#define F_WRITE_BYTES (F_OFFSET+212)
#define F_WRITE_FILE (F_OFFSET+213)
#define F_PROTECTED_EXTRACT_LVALUE (F_OFFSET+256)
#define F_UNDEF (F_OFFSET+257)
#define F_END_CATCH (F_OFFSET+258)
#define F_BREAK_CONTINUE (F_OFFSET+259)
#define F_BREAKN_CONTINUE (F_OFFSET+260)
#define F_NR_RANGE (F_OFFSET+261)
#define F_RN_RANGE (F_OFFSET+262)
#define F_RR_RANGE (F_OFFSET+263)
#define F_EXTRACT1 (F_OFFSET+264)
#define F_PUSH_PROTECTED_INDEXED_LVALUE (F_OFFSET+265)
#define F_PUSH_PROTECTED_RINDEXED_LVALUE (F_OFFSET+266)
#define F_PUSH_PROTECTED_INDEXED_MAP_LVALUE (F_OFFSET+267)
#define F_NR_RANGE_LVALUE (F_OFFSET+268)
#define F_RN_RANGE_LVALUE (F_OFFSET+269)
#define F_RR_RANGE_LVALUE (F_OFFSET+270)
#define F_PROTECTED_INDEX_LVALUE (F_OFFSET+271)
#define F_PROTECTED_RINDEX_LVALUE (F_OFFSET+272)
#define F_PROTECTED_RANGE_LVALUE (F_OFFSET+273)
#define F_PROTECTED_NR_RANGE_LVALUE (F_OFFSET+274)
#define F_PROTECTED_RN_RANGE_LVALUE (F_OFFSET+275)
#define F_PROTECTED_RR_RANGE_LVALUE (F_OFFSET+276)
#define F_ACOS (F_OFFSET+277)
#define F_ALLOCATE_MAPPING (F_OFFSET+278)
#define F_ASIN (F_OFFSET+279)
#define F_ATAN (F_OFFSET+280)
#define F_CALL_RESOLVED (F_OFFSET+281)
#define F_CALLER_STACK_DEPTH (F_OFFSET+282)
#define F_COPY_MAPPING (F_OFFSET+283)
#define F_COS (F_OFFSET+284)
#define F_EXP (F_OFFSET+285)
#define F_EXTERN_CALL (F_OFFSET+286)
#define F_EXTRACT (F_OFFSET+287)
#define F_GARBAGE_COLLECTION (F_OFFSET+288)
#define F_GET_EVAL_COST (F_OFFSET+289)
#define F_GET_TYPE_INFO (F_OFFSET+290)
#define F_LOG (F_OFFSET+291)
#define F_MAPPING_CONTAINS (F_OFFSET+292)
#define F_PREVIOUS_OBJECT (F_OFFSET+293)
#define F_PROGRAM_TIME (F_OFFSET+294)
#define F_QUERY_IMP_PORT (F_OFFSET+295)
#define F_QUERY_INPUT_PENDING (F_OFFSET+296)
#define F_QUERY_IP_NAME (F_OFFSET+297)
#define F_QUERY_IP_NUMBER (F_OFFSET+298)
#define F_QUERY_MUD_PORT (F_OFFSET+299)
#define F_QUERY_ONCE_INTERACTIVE (F_OFFSET+300)
#define F_RAISE_ERROR (F_OFFSET+301)
#define F_REFERENCEP (F_OFFSET+302)
#define F_SET_EXTRA_WIZINFO_SIZE (F_OFFSET+303)
#define F_SIN (F_OFFSET+304)
#define F_SQRT (F_OFFSET+305)
#define F_STRSTR (F_OFFSET+306)
#define F_SWAP (F_OFFSET+307)
#define F_TAN (F_OFFSET+308)
#define F_TO_ARRAY (F_OFFSET+309)
#define F_TO_FLOAT (F_OFFSET+310)
#define F_TO_INT (F_OFFSET+311)
#define F_TO_STRING (F_OFFSET+312)
#define F_TYPEOF (F_OFFSET+313)
#define F_EXTRACT_LVALUE (F_OFFSET+384)
#define F_ADD_VERB (F_OFFSET+385)
#define F_ADD_XVERB (F_OFFSET+386)
#define F_ATTACH_ERQ_DEMON (F_OFFSET+387)
#define F_BINARY_MESSAGE (F_OFFSET+388)
#define F_DEBUG_MESSAGE (F_OFFSET+389)
#define F_EFUN308 (F_OFFSET+390)
#define F_EXPAND_DEFINE (F_OFFSET+391)
#define F_FUNCTIONLIST (F_OFFSET+392)
#define F_GET_ERROR_FILE (F_OFFSET+393)
#define F_GET_EXTRA_WIZINFO (F_OFFSET+394)
#define F_HEART_BEAT_INFO (F_OFFSET+395)
#define F_INHERIT_LIST (F_OFFSET+396)
#define F_QUERY_EDITING (F_OFFSET+397)
#define F_QUERY_IDLE (F_OFFSET+398)
#define F_QUERY_SHADOWING (F_OFFSET+399)
#define F_QUERY_SNOOP (F_OFFSET+400)
#define F_REGEXPLODE (F_OFFSET+401)
#define F_REGREPLACE (F_OFFSET+402)
#define F_REMOVE_ACTION (F_OFFSET+403)
#define F_REMOVE_INTERACTIVE (F_OFFSET+404)
#define F_RENAME_OBJECT (F_OFFSET+405)
#define F_SEND_ERQ (F_OFFSET+406)
#define F_SEND_IMP (F_OFFSET+407)
#define F_SET_AUTO_INCLUDE_STRING (F_OFFSET+408)
#define F_SET_BUFFER_SIZE (F_OFFSET+409)
#define F_SET_CONNECTION_CHARSET (F_OFFSET+410)
#define F_SET_DRIVER_HOOK (F_OFFSET+411)
#define F_SET_EXTRA_WIZINFO (F_OFFSET+412)
#define F_SET_IS_WIZARD (F_OFFSET+413)
#define F_SET_MODIFY_COMMAND (F_OFFSET+414)
#define F_SET_PROMPT (F_OFFSET+415)
#define F_SET_THIS_PLAYER (F_OFFSET+416)
#define F_SHADOW (F_OFFSET+417)
#define F_SHUTDOWN (F_OFFSET+418)
#define F_SYMBOL_VARIABLE (F_OFFSET+419)
#define F_TO_OBJECT (F_OFFSET+420)
#define F_TRACE (F_OFFSET+421)
#define F_TRACEPREFIX (F_OFFSET+422)
#define F_TRANSPOSE_ARRAY (F_OFFSET+423)
#define F_UNBOUND_LAMBDA (F_OFFSET+424)
#define F_UNSHADOW (F_OFFSET+425)
#define F_WIZLIST_INFO (F_OFFSET+426)
#define F_DEBUG_INFO (F_OFFSET+512)
#define F_FILTER_OBJECTS (F_OFFSET+513)
#define F_MAP_OBJECTS (F_OFFSET+514)
#define F_WALK_MAPPING (F_OFFSET+515)
