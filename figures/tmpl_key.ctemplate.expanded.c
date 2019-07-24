int tmpl_key(char *buffer, int buffer_len, SqlKey *key)
{
    char *buff_ptr = buffer;
    int written;;
    char *tableName = "";
    char *columnName = "";
    SqlValue *value;

    if(key->table) {
        (value) = (key->table->tableName)->v.value;
        tableName = value->v.reference;
    }
    if(key->column) {
        (value) = (key->column->columnName)->v.value;
        columnName = value->v.reference;
    }

    do {
        written = snprintf(buff_ptr, buffer_len - (buff_ptr - buffer), "^|\"%s\"|%s(cursorId,\"keys\",%d,\"%s\",\"%s\")", config->global_directory, config->global_names.raw_cursor, key->unique_id, tableName, columnName );
        if(written > buffer_len - (buff_ptr - buffer)) {
            FATAL >= config->record_error_level ? octo_log(38, "/home/charles/p/OctoSQL/build_commands/src/tmpl_key.ctemplate.c", FATAL, ERR_BUFFER_TOO_SMALL, "") : (void)0;;
        }
        buff_ptr += written;
    } while(0);

    return buff_ptr - buffer;;
}
