/*
* PNGR.H -- Prototypes for QImageIO read/write handlers for
*	the PNG graphic format using libpng.
*
*	Copyright (c) October 1998, Sirtaj Singh Kang.
*	Distributed under the LGPL.
*
*	$Id: pngr.h,v 1.1 1998/10/23 14:10:09 ssk Exp $
*/
#ifndef	_SSK_PNGR_H
#define _SSK_PNGR_H

class QImageIO;

void kimgio_png_read( QImageIO *io );
void kimgio_png_write(QImageIO *io );

#endif
