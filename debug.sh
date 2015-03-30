#!/bin/sh
cgdb --args ./wtrs --docroot ".;/doc-root" --approot app-root  --http-address=0.0.0.0 --http-port=8000 -c app-root/wtrs.xml
