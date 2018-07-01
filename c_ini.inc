#if defined _included_c_ini
    #endinput
#endif

#define _included_c_ini

#define cini_Exists \
	fexist
	
#define MAX_FIELD_NAME 32
#define MAX_FIELD_VALUE 256

stock cini_Create(const file[]) {
	if (cini_Exists(file)) {
		return 0;
	}

	new File:fileveriable = fopen(file, io_write);
	if (!fileveriable) {
		fclose(fileveriable);
	}

	else return 0;
	
	return 1;
}

stock cini_Write(file[], key[], buf[])
{
	if(!fexist(file))
		return 0;
	
	new File:h = fopen(file, io_readwrite);
	
	if(!h) {
		return 0;
	
	}
	new temp[256], string[256], line;
	while(fread(h, temp))
	{
		line = strlen(temp);
	}
	
	if(temp[line-2] == '\r' || temp[line-2] == '\n')
	{
		format(string, sizeof(string), "%s=%s", key, buf);
	}
	
	else
		format(string, sizeof(string), "\r\n%s=%s", key, buf);
	
	fwrite(h, string);
	
	fclose(h);
	return 1;
}

stock Float:cini_Write_Float(file[], key[], Float:buf)
{
	if(!fexist(file))
		return 0;
	
	new File:h = fopen(file, io_readwrite);
	
	if(!h) {
		return 0;
	
	}
	new temp[256], string[size], line;
	while(fread(h, temp))
	{
		line = strlen(temp);
	}
	
	if(temp[line-2] == '\r' || temp[line-2] == '\n')
	{
		format(string, sizeof(string), "%s=%f", key, buf);
	}
	
	else
		format(string, sizeof(string), "\r\n%s=%f", key, buf);
	
	fwrite(h, string);
	
	fclose(h);
	return 1;
}

stock cini_Write_Int(file[], key[], buf)
{
	if(!fexist(file))
		return 0;
	
	new File:h = fopen(file, io_readwrite);
	
	if(!h) {
		return 0;
	
	}
	new temp[256], string[256], line;
	while(fread(h, temp))
	{
		line = strlen(temp);
	}
	
	if(temp[line-2] == '\r' || temp[line-2] == '\n')
	{
		format(string, sizeof(string), "%s=%d", key, buf);
	}
	
	else
		format(string, sizeof(string), "\r\n%s=%d", key, buf);
	
	fwrite(h, string);
	
	fclose(h);
	return 1;
}

stock cini_Read(file[], key[], buf[])
{
	if(!fexist(file))
		return 0;
	
	new File:h = fopen(file, io_read);
	
	if(!h) {
		return 0;
	
	}
	new tempex[256], del;
	new pos, temp[256], line;
	while(fread(h, temp))
	{
		pos += strfind(temp, "=");
		line += strlen(temp);
	
		if(strfind(temp, key) != -1) 
		{	
			if(( del = strfind(temp, "\r")) != -1)
				strdel(temp, del, line);
			
			pos = strfind(temp, "=");
			strmid(tempex, temp, pos+1, line);
			format(buf, 256, tempex);
		}
	}
	fclose(h);
	return 1;
}

stock Float:cini_Read_Float(file[], key[])
{
	if(!fexist(file))
		return Float:1;
	
	new File:h = fopen(file, io_read);
	
	if(!h) {
		return Float:1;
	
	}
	new tempex[256], del;
	new pos, temp[256], line;
	while(fread(h, temp))
	{
		pos += strfind(temp, "=");
		line += strlen(temp);
	
		if(strfind(temp, key) != -1) 
		{	
			if(( del = strfind(temp, "\r")) != -1)
				strdel(temp, del, line);
			
			pos = strfind(temp, "=");
			strmid(tempex, temp, pos+1, line);
		}
	}
	fclose(h);
	return floatstr(tempex);
}

stock cini_Read_Int(file[], key[])
{
	if(!fexist(file))
		return 0;
	
	new File:h = fopen(file, io_read);
	
	if(!h) {
		return 0;
	
	}
	new tempex[256], del;
	new pos, temp[256], line;
	while(fread(h, temp))
	{
		pos += strfind(temp, "=");
		line += strlen(temp);
	
		if(strfind(temp, key) != -1) 
		{	
			if(( del = strfind(temp, "\r")) != -1)
				strdel(temp, del, line);
			
			pos = strfind(temp, "=");
			strmid(tempex, temp, pos+1, line);
		}
	}
	fclose(h);
	return strval(tempex);
}

// Code By cngznNN