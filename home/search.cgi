#!/usr/bin/perl

# search.cgi
#   Sam's hack for quickly searching the course Web.  Primarily
#   cut-and-pasted from Perl code originally written in 1995 (!)
#   and last updated in 2001.

# +-------+-----------------------------------------------------------
# | Notes |
# +-------+

# * To cache search results, create the directory $ROOT/search and
#   make it readable and writable by the web user (www-data on MathLAN).

# * Usage can be found by grepping search.cgi in /var/logs/apache2/access.log
#   It looks like the logs are compressed every Sunday.

# +------+------------------------------------------------------------
# | Todo |
# +------+

# [ ] The todo list really should be on the github page :-)

# [ ] Improve the search for translated files by identifying the 
#     source files with grep and then grepping again in the HTML
#     versions of those files.  (Or it may not be worth it.)

# +----------+--------------------------------------------------------
# | Settings |
# +----------+

# $ROOT
#   The root of the course Web site
my $ROOT = $ENV{"PWD"} . "..";

# $PATTERNS
#   A space-separated list of all the files to search
my $PATTERNS = "$ROOT/home/*.sect $ROOT/handouts/*.sect $ROOT/readings/*.sect $ROOT/outlines/*.md $ROOT/eboards/*.md $ROOT/labs/*.sect $ROOT/reference/*.sect $ROOT/assignments/*.sect";

# $DEBUG
#   Are we debugging or not
$DEBUG = 0; 		# Set to 1 if you want to debug

# $GREP
#   The version of grep to use
$GREP = "/bin/grep -H";

# +------+------------------------------------------------------------
# | Main |
# +------+

local($exitval) = main();
exit $exitval;

sub main() {
  # Set up variables
  my $query = getQuery();
  my $keyword = extractField($query, "keyword");

  # Clean up the query for safety
  $keyword =~ s/[^-_0-9 a-zA-Z.]/./g;

  # my $template = minimalTemplate();
  my $template = readFile("template.html");

  return searchPage($template, $keyword, $PATTERNS, "search.cgi");
} # main

# +---------+---------------------------------------------------------
# | Helpers |
# +---------+

# Routines
#   extractField(query,fieldname)
# Returns
#   The value for the field.  If there are multiple values, they
#   will be returned with commas separating them.
sub extractField($$) {
  my $query = shift;    # The query string
  my $fld = shift;      # The field name we're looking for

  my $result = "";      # The result of extracting the field
  my $match;            # For pattern matching
  my $next;             # The next set of field contents

  # Keep finding versions of the field that follow an ampersand.  Note
  # that we remove from the back, rather than from the front.
  while (($match=$query) =~ m/&${fld}=/) {
    $next = $query;
    $next =~ s/.*&${fld}=([^&]*).*/$1/;
    $result = "$next,$result";
    $query =~ s/(.*)&${fld}=.*/$1/;
  }
  # See if we're left with something that matches
  if (($match=$query) =~ m/^${fld}=/) {
    $next = $query;
    $next =~ s/&.*//;           # Remove any subsequent fields
    $next =~ s/${fld}=//;       # Remove the field name
    $result = "$next,$result";
  } # if there is anything left that matches

  # We're done
  $result =~ s/,$//;
  return webDecode($result);
} # extractField

# Routine
#   extractHtmlTitle(fname)
# Parameters
#   fname, the name of a file
# Purpose
#   Find the title in the file.  
sub extractHtmlTitle($) {
  my $fname = shift;
  my $contents = readFile($fname);
  $contents =~ s/.*<title>//gis;
  $contents =~ s/<\/title>.*//gis;
  $contents =~ s/\n/ /gis;
  return $contents;
} # extractHtmlTitle

# Routine
#   extractSectTitle(fname)
# Parameters
#   fname, the name of a .sect file
# Purpose
#   Find the title in the file.  
sub extractSectTitle($) {
  my $fname = shift;
  my $contents = firstLine($fname);
  $contents =~ s/.*<title>//gis;
  $contents =~ s/<\/title>.*//gis;
  $contents =~ s/\n/ /gis;
  return $contents;
} # extractSectTitle

# Routine
#   firstLine
# Parameters
#   fname, the name of a file
# Purpose:
#   Extract and return the first line of the file
# Produces:
#   line, a string
sub firstLine($) {
  my $fname = shift;
  open(FL, "< $fname");
  my $line = <FL>;
  close(FL);
  return $line;
} # firstLine

# Routine
#   getTitle(fname)
# Description
#   Gets the title of the given file
sub getTitle($) {
  $fname = shift;

  # .html files are easy
  if ($fname =~ m/html$/) {
     return extractHtmlTitle($fname);
  } # .html file

  # If we don't have a .html file, let's see if we can get one.
  my $htmlfile = $fname;
  $htmlfile =~ s/\.[^.]*$//;
  $htmlfile .= ".html";
  if (-e $htmlfile) {
    return extractHtmlTitle($htmlfile);
  } # Equiv HTML file exists

  # Things aren't going so hot.  We don't have a corresponding
  # .html file.  But that's okay.  We have other approaches
  if ($fname =~ m/sect$/) {
    return extractSectTitle($fname);
  } # Original is a .sect file
  else {
    return firstLine($fname);
  } # Text file, or so I hope
} # getTitle

# Routine:
#   getQuery()
# Description:
#   Looks up and returns the query string.  If it seems to have been called
#   from the command line, reads the query string from stdin.
# Note:
#   Based on code on p. 130 of "Teach Yourself CGI Programming in Perl"
sub getQuery {
  my($query);
  if ($ENV{"REQUEST_METHOD"} eq "GET") {
    $query = $ENV{'QUERY_STRING'};
  }
  elsif ($ENV{"REQUEST_METHOD"} eq "POST") {
    read(STDIN, $query, $ENV{'CONTENT_LENGTH'});
  } # If there's none, try standard in
  elsif ($ENV{"REQUEST_METHOD"} eq "") {
    $query = "";
     while (<STDIN>) {
       $query .= $_;
        chop($query);
     }
  }
  else {
    $query = "";
  } # default
  return $query;
} # getQuery

# Routine:
#   minimalTemplate()
# Purpose:
#   Generate a minimal HTML template for this program
# Produces:
#   template, a string
sub minimalTemplate() {
  my $template = <<"TEMPLATE";
<html>
<head>
<title>*TITLE*</title>
</head>
<body>
*BODY*
</body>
</html>
TEMPLATE
} # minimalTemplate

# Routine
#   printHttpPrologue()
# Purpose:
#   Print the standard prologue for an HTTP return
sub printHttpPrologue() {
  print <<"HTTP_INFO";
Content-type: text/html

HTTP_INFO
} # printHttpPrologue

# Routine:
#   readFile(fname)
# Purpose:
#   Read in the contents of a file.
# Produces:
#   The contents of that file
sub readFile($)
{
  my $filename = shift;
  open(PORT, "< $filename");
  my $contents = readPort(PORT);
  close(PORT);
  return $contents;
} # readFile

# Routine:
#   readPort(port)
# Purpose:
#   Read in the contents of a port.
# Produces:
#   The contents of the port.
# Ponderings:
#   Separate from readFile so that we can use it in other contexts
#   (e.g., reading the output of piped data).
sub readPort
{
  my $PORT = shift;
  my $linesep = $/;     # Save for later
  undef $/;             # When %/ is undefined, read reads the whole file
  my $contents = <$PORT>;
  $/ = $linesep;        # Restore
  return $contents;
} # readPort

# Routine:
#   searchPage(template,keyword,places_to_search,searchURL)
# Description:
#   Builds and prints a simple Web page of search results.
# Returns:
#   An appropriate exit value (0 for success, something else for failure)
# Parameters
#   template is a template HTML page with *TITLE* for the title and
#     *BODY* for the body
#   places_to_search is a space-separated list of "patterns", such
#     as "/home/rebelsky/Web/*.html"
sub searchPage($$$$) {
  my $template = shift;
  my $keyword = shift;
  my $PATTERNS = shift;
  my $searchURL = shift;
  if (!$searchURL) { $searchURL = "search.cgi"; }

  my $RESULTS;  # File handle for results

  if ($keyword) {
    $title = "Search for '$keyword'";
  }
  else {
    $title = "Simple Search Engine";
  }

  # Build the file name for the cached results page
  my $resultsPage = $keyword;
  $resultsPage =~ s/[^a-zA-Z0-9]/_/g;
  $resultsPage = "../search/$resultsPage.html";
  print STDERR "Results: $resultsPage\n";

  # Print the initial header so that we can print things along
  # the way for debugging.
  printHttpPrologue();

  # If the results page does not exist or is old, build a new one
  if ((!(-f $resultsPage)) || ((-M $resultsPage) > 1)) {
    if (! open($RESULTS, "> $resultsPage")) {
      $RESULTS = STDOUT;
    }

    $template =~ s/\*TITLE\*/$title/g;
    my @template = split /\*BODY\*/,$template;
    
    # Print the first half of the template
    print $RESULTS $template[0];
  
    # Print the date (so that they know when they searced)
    # Identify the date
    if ($keyword) {
      my($date) = `date`; chop($date);
      print $RESULTS "<p><em>Search conducted on $date.</em><\/p>\n";
    }
  
    # Identify all portions that contain the appropriate stuff
    # We need to do separate greps in case there are too many files
    if ($keyword) {
      my($found) = "";
      my($pattern);
      my($morefound);
      foreach $pattern (split(/\s+/,$PATTERNS)) {
        if ($pattern) {
          if ($DEBUG) { print "Looking at pattern '$pattern'<br>\n"; }
          $morefound = `$GREP -i "$keyword" $pattern`;
          if ($morefound) {
            if ($DEBUG) { print "Found stuff<br>\n"; }
            $found .= $morefound;
          } # if more stuff was found 
        } # if the pattern matched
      } # foreach pattern
    
      # Get rid of HTML commands from that stuff
      if ($DEBUG) {
        # We need to change all tags to "plain text" for printing out
        my($tmp) = $found;
        $tmp =~ s/\&/\&amp;/g;
        $tmp =~ s/>/\&gt;/g;
        $tmp =~ s/</\&lt;/g;
        print "Search results: $tmp<br>";
      }
      $found =~ s/<[^>]*>//g;
      $found =~ s/<[^>]*$//;
      if ($DEBUG) {
        print "Cleaned up: $found<br>";
      }
    
      # Build HTML containing the found lines (which may not be the
      # same as those before, given the stripping of HTML)
      my @lines = split(/\n/, $found);	# All the found lines
      my $line;				# One such line
      my $newfile,$contents;		# One line of info
      my $fname;				# The last file mentioned
      my $html = "";			# The HTML for all of this
      my $title;				# The title of the file
      my $dir;				# The directory in which it is found
      foreach $line (@lines) {
        if ($DEBUG) { print "Considering '$line'<br>\n"; }
        # The pattern is ":.*$keyword" so that we ensure that the keyword
        # falls in the body and not the filename
        if ($line =~ m/:.*$keyword/i) {
          # Split the line into filename and matching info
          ($newfile,$contents) = split(/:/,$line,2);
          
  	# Update the file name to deal with .md and .sect files
          $newfile =~ s/md$/html/;
          $newfile =~ s/sect$/html/;
  
          # Identify the parent directory (which clarifies location)
          $dir = $newfile;
          if ($dir !~ s/\/[^\/]*$//) {
            $dir = "";
          }
          $dir =~ s/^.*\///;
  
          if ($DEBUG) {
            print "&nbsp;&nbsp;File: $newfile<br>\n";
            print "&nbsp;&nbsp;Dir: $dir<br>\n";
            print "&nbsp;&nbsp;Contents: $contents<br>\n";
          }
  
          # If the file is different, make a new entry
          if ($newfile ne $fname) {
            if ($DEBUG) { print "Starting a new entry!\n"; }
            $fname = $newfile;
    
            # End the old entry (we know that there's an old entry b/c we've
            # actually generated some HTML)
            if ($html) { $html .= "</ul>\n\n"; }
   
            # Begin the new entry
            $title = getTitle($fname);
            if (!$title) { $title = $fname; }
            # if ($dir) { $html .= "[$dir] "; }
  
            # Convert the file name fo a url
  	  my $url = $fname;
  	  $url =~ s/^\/home\//http:\/\/www.cs.grinnell.edu\/~/;
  	  $url =~ s/public_html\///;
  	  $url =~ s/Web\///;
  
            $html .= "<strong><a href=\"$url\">$title</a></strong>\n";
            $html .= "<ul>\n";
          }
      
          # Emphasize the keyword
          $contents =~ s/(${keyword})/<strong>$1<\/strong>/ig;
      
          # Write the matching line
          $html .= "<li>... $contents ...</li>\n";
        } # if the keyword is on the line
      } # foreach $line
    
      # See if we found something
      if (!$html) {
        print $RESULTS <<"NOTFOUND";
  <P>
  <em>Sorry, I am unable to find any pages that contain the text <strong>$keyword</strong>.</em>
  </P>
NOTFOUND
      } # if we didn't find something
  
      else {
        print $RESULTS <<"FOUND";
  <p>
    For each of the files that contains the word
    <q><strong>${keyword}</strong></q>, the file and lines with the word
    <q><strong>${keyword}</strong></q> are listed.  Click on the name of a
    file to view that file.
  </p>
    
  <p>
    The limitations of WWW and HTML currently make it difficult, if not
    impossible, to allow you to jump directly to a particular line in
    a page.  After navigating to the page, you may use the search function of 
    your Web browser to find <q>${keyword}</q>.
  </p>
  <hr>
  $html
  </ul>
FOUND
      } # if something was found
    } # if there's a keyword
  
    # Print the search form
    print $RESULTS <<"FORM";
  <hr width="50%">
  <form method="get" action="$searchURL">
  Enter a word or phrase to search for:
  <input type="text" name="keyword">
  <input type="submit" value="Search">
  </form>
FORM
  
    # Print the remaining HTML
    print $RESULTS $template[1];
  } // if

  # And we're done
  close($RESULTS);

  # That's it.  The file can now be printed.
  print readFile($resultsPage);
  return 0;
} # searchPage 

# Routine
#   webDecode(txt)
# Description
#   Decodes text given as part of a web query
sub webDecode {
  my $str = shift;
  $str =~ s/\+/ /g;
  $str =~ s/%(..)/pack("c",hex($1))/ge;
  return $str;
} # webDecode

