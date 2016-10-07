////////////////
//
// jpeg.h -- QImage IO handler declaration for JFIF JPEG graphic format,
//	SirtaJ Singh Kang <taj@kde.org>, December 1996.
//           using IJG JPEG library.
//

// $Id: jpeg.h,v 1.1.1.1 1998/10/18 04:43:02 ssk Exp $

#ifndef _SSK_JPEG_QHANDLERS_H
#define _SSK_JPEG_QHANDLERS_H

class QImageIO;

//////
// JPEG IO handlers for QImage.
//

void kimgio_jpeg_read(QImageIO *image);
void kimgio_jpeg_write(QImageIO *image);

#endif
