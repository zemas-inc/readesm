/* Copyright 2009 Andreas Gölzer

This file is part of readESM.

readESM is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

readESM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with readESM.  If not, see <http://www.gnu.org/licenses/>. */
#ifndef I18N_H
#define I18N_H I18N_H

#include <libintl.h>
#include <locale.h>
#include "typedefs.h"

void i18nInit(){
	setlocale( LC_ALL, "" );
	bindtextdomain( "readesm", "locale" );
	textdomain( "readesm" );
}

string tr(string in){
	return (in == "") ? "" : gettext(in.c_str());
}

string tr(const char* in){
	return *in == 0 ? "" : gettext(in);
}

char* trc(const char* in){
	return gettext(in);
}

string latin1tounicode(unsigned char in){
	ostringstream o;
	if(in <= 127){
		o << in;
		return o.str();
	}
	if(in < 160) return "";
	const char* conversion[]= { " ", "¡", "¢", "£", "¤", "¥", "¦", "§", "¨", "©", "ª", "«", "¬",  "", "®", "¯", \
				    "°", "±", "²", "³", "´", "µ", "¶", "·", "¸", "¹", "º", "»", "¼", "½", "¾", "¿", \
				    "À", "Á", "Â", "Ã", "Ä", "Å", "Æ", "Ç", "È", "É", "Ê", "Ë", "Ì", "Í", "Î", "Ï", \
				    "Ð", "Ñ", "Ò", "Ó", "Ô", "Õ", "Ö", "×", "Ø", "Ù", "Ú", "Û", "Ü", "Ý", "Þ", "ß", \
				    "à", "á", "â", "ã", "ä", "å", "æ", "ç", "è", "é", "ê", "ë", "ì", "í", "î", "ï", \
				    "ð", "ñ", "ò", "ó", "ô", "õ", "ö", "÷", "ø", "ù", "ú", "û", "ü", "ý", "þ", "ÿ" };
	if(in < 256) return conversion[in - 160];
}
#endif