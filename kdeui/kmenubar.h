/* This file is part of the KDE libraries
    Copyright (C) 1997 Sven Radej (sven.radej@iname.com)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/
//Revision 1.17  1999/03/06 18:03:34  ettrich
//the nifty "flat" feature of kmenubar/ktoolbar is now more visible:
//It has its own menu entry and reacts on simple LMP clicks.
#include <qmenubar.h> 
#ifndef _KMENUBAR_H
#define _KMENUBAR_H

class _menuBar : public QMenuBar
 {
   Q_OBJECT
     
 public:
   _menuBar(QWidget *parent=0, const char *name=0);
   ~_menuBar();
 };

#include <qmenubar.h>
 * This is floatable toolbar. It can be set to float, Top, or Bottom
 * of KTopLevelWidget. It can be used without of KTopLevelWidget,
 * but then you should maintain items (toolbars, menubar, statusbar)
 * yourself. Interface is the same as QMenuBar, except that you can't
 * add pixmaps. Signals are not implemented.
 *
 * Interface is the same as QMenuBar, except that you can't
 * add pixmaps.
 * @short KDE floatable menubar
 * If you want to add other methods for 100% compatibility with QMenuBar
 * just add those methods, and pass all arguments ot menu bar.
 * see kmenubar.cpp for details. It is extremly simple.
 * @author Sven Radej <sven@kde.org>
 */
class KMenuBar : public QFrame
 {
   Q_OBJECT

 public:
   enum menuPosition{Top, Bottom, Floating};
   /**
    * Positions of menubar.
    * Constructor

   /**
    * Constructor. For all details about inserting items see
    * @ref QMenuBar
    */
   KMenuBar( QWidget *parent=0, const char *name=0);

   /**
    * Destructor. Embeds menubar back if floating. Delete menubar
    * in your destructor or closeEvent for 100% safety
    */
    * menubar can be moved wit @ref setMenuBarPos.

   /**
    * Enable or disable moving. This only disables user moving
    * menubar can be moved wit @ref #setMenuBarPos.
    */
   void enableMoving(bool flag = TRUE);

   /**
    * Returns menubar position.
    */
   menuPosition menuBarPos() {return position;};
   void enableFloating (bool flag = TRUE);
   /**
    * Enables/disables floating.
    */
   void enableFloating(bool flag = TRUE);

   /**
    * Sets position. Can be used when floating or moving is disabled.
    */
   void setMenuBarPos(menuPosition mpos);
   void setTitle(const char *_title) {title = _title;};
   /**
    * Sets title for floating menu bar. Default is Main widget title.
    */
   void setTitle(const QString&_title) {title = _title;};

   uint count();
   int insertItem(const char *text,
    * details.
    */
   int insertItem(const char *text, int id=-1, int index=-1 );
   int insertItem(const char *text, QPopupMenu *popup,
                  int accel=0 );

   void insertSeparator(int index=-1 );
   void removeItem(int id);
   void removeItemAt(int index);
   void clear();
   int accel(int id);
   void setAccel(int key, int id );
   const char *text(int id);
   void changeItem(const char *text, int id);
   void setItemChecked(int id , bool flag);
   void setItemEnabled(int id, bool flag);

   int heightForWidth ( int max_width ) const; 
   virtual void setItemEnabled(int id, bool flag);
   int heightForWidth ( int max_width ) const;

   void setFlat (bool);

 protected slots:
   void ContextCallback(int index);
   
   void slotHighlighted (int id);
   void slotHotSpot (int i);

 protected:

   void init();
   void mousePressEvent ( QMouseEvent *m );
   void resizeEvent( QResizeEvent *e );
   
 private:
   void leaveEvent (QEvent *e);
   bool eventFilter(QObject *, QEvent *);

private:
   bool moving;
   const char *title;
   int oldX;
   int oldY;
   int oldWFlags;
   
   menuPosition position;
   menuPosition lastPosition;
   menuPosition movePosition;
     
   QPopupMenu *context;
   QMenuBar *menu;
     * This signal is connected to KTopLevel::updateRects. It is

signals:
    /**
     * emited when menu bar changes its position.
     */
    void moved (menuPosition);

    /**
     * This signal is emited when item id is highlighted.
     */
    void highlighted(int id);

    /**
 private:
     */
    void activated(int id);

private:
   QFrame *handle;
   KToolBoxManager *mgr;
   bool highlight;
   bool transparent;
   bool buttonDownOnHandle;
 };

#endif
