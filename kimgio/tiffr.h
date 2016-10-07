/**
* QImageIO Routines to read/write TIFF images.
* Sirtaj Singh Kang, Oct 1998.
*
* $Id: tiffr.h,v 1.1.1.1 1998/10/18 04:43:02 ssk Exp $
*/

#ifndef KIMG_TIFFR_H
#define KIMG_TIFFR_H

class QImageIO;

void kimgio_tiff_read( QImageIO *io );
void kimgio_tiff_write( QImageIO *io );

#endif
