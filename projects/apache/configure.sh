#!/bin/bash
#sudo chown -R $USER:$USER /var/www/html/
cgiload=$(cat /etc/apache2/mods-available/cgi.load)
echo $cgiload
