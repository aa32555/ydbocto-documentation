
/****************************************************************
 *								*
 * Copyright (c) 2019 YottaDB LLC and/or its subsidiaries.	*
 * All rights reserved.						*
 *								*
 *	This source code contains the intellectual property	*
 *	of its copyright holder(s), and is made available	*
 *	under a license.  If you do not know the terms of	*
 *	the license, please stop and do not read further.	*
 *								*
 ****************************************************************/

#include <ctype.h>

#include "octo_types.h"
#include "logical_plan.h"

#include "physical_plan.h"
#include "template_helpers.h"

TEMPLATE(tmpl_key, SqlKey *key)
{
    TEMPLATE_INIT();
    char *tableName = "";
    char *columnName = "";
    SqlValue *value;

    if(key->table) {
        UNPACK_SQL_STATEMENT(value, key->table->tableName, value);
        tableName = value->v.reference;
    }
    if(key->column) {
        UNPACK_SQL_STATEMENT (value, key->column->columnName, value);
        columnName = value->v.reference;
    }

    do {
        written = snprintf(buff_ptr, buffer_len - (buff_ptr - buffer), "^|\"%s\"|%s(cursorId,\"keys\",%d,\"%s\",\"%s\")", config->global_directory, config->global_names.raw_cursor, key->unique_id, tableName, columnName );
        if(written > buffer_len - (buff_ptr - buffer)) {
            FATAL(ERR_BUFFER_TOO_SMALL, "");
        }
        buff_ptr += written;
    } while(0);

    TEMPLATE_END();
}


