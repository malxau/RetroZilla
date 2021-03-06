/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Christopher Blizzard. Portions created by Christopher Blizzard are Copyright (C) Christopher Blizzard.  All Rights Reserved.
 * Portions created by the Initial Developer are Copyright (C) 2001
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Christopher Blizzard <blizzard@mozilla.org>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include <nsISupports.h>
#include <nsCOMPtr.h>
#include <nsIOutputStream.h>
#include <nsIInputStream.h>
#include <nsILoadGroup.h>
#include <nsIChannel.h>
#include <nsIStreamListener.h>
#include <nsIWebBrowser.h>

class nsEmbedStream : public nsIInputStream 
{
 public:

  nsEmbedStream();
  virtual ~nsEmbedStream();

  void      InitOwner      (nsIWebBrowser *aOwner);
  NS_METHOD Init           (void);

  NS_METHOD OpenStream     (nsIURI *aBaseURI, const nsACString& aContentType);
  NS_METHOD AppendToStream (const PRUint8 *aData, PRUint32 aLen);
  NS_METHOD CloseStream    (void);

  NS_METHOD Append         (const PRUint8 *aData, PRUint32 aLen);

  // nsISupports
  NS_DECL_ISUPPORTS
  // nsIInputStream
  NS_DECL_NSIINPUTSTREAM

 private:
  nsCOMPtr<nsIOutputStream>   mOutputStream;
  nsCOMPtr<nsIInputStream>    mInputStream;

  nsCOMPtr<nsILoadGroup>      mLoadGroup;
  nsCOMPtr<nsIChannel>        mChannel;
  nsCOMPtr<nsIStreamListener> mStreamListener;

  PRUint32                    mOffset;
  PRBool                      mDoingStream;

  nsIWebBrowser              *mOwner;

};
