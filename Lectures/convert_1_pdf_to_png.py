#!/usr/bin/python

import os, sys

print 'Number of arguments:', len(sys.argv), 'arguments.'
print 'Argument List:', str(sys.argv)

if ( len( sys.argv ) < 2 ):
    print( "Please specify the PDF file to convert." )
    sys.exit()

filename = sys.argv[1]

if ( ".pdf" in filename ):
    # convert to png
    print( filename )
    directory = filename + "_slides"
    os.system( "mkdir " + directory )

    os.system( "convert -verbose -density 150 " + filename + " " + directory + "/slide.png" )









