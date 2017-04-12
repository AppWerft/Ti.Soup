/* C++ code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf -L C++ -E -t /private/var/folders/dp/_57t8_6j247dh0h7mknf97600000gn/T/fuerst/soup-generated/KrollGeneratedBindings.gperf  */
/* Computed positions: -k'' */

#line 3 "/private/var/folders/dp/_57t8_6j247dh0h7mknf97600000gn/T/fuerst/soup-generated/KrollGeneratedBindings.gperf"


#include <string.h>
#include <v8.h>
#include <KrollBindings.h>

#include "de.appwerft.soup.DocumentProxy.h"
#include "de.appwerft.soup.SoupModule.h"
#include "de.appwerft.soup.ElementProxy.h"
#include "de.appwerft.soup.JSONObjectProxy.h"


#line 16 "/private/var/folders/dp/_57t8_6j247dh0h7mknf97600000gn/T/fuerst/soup-generated/KrollGeneratedBindings.gperf"
struct titanium::bindings::BindEntry;
/* maximum key range = 6, duplicates = 0 */

class SoupBindings
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static struct titanium::bindings::BindEntry *lookupGeneratedInit (const char *str, unsigned int len);
};

inline /*ARGSUSED*/
unsigned int
SoupBindings::hash (register const char *str, register unsigned int len)
{
  return len;
}

struct titanium::bindings::BindEntry *
SoupBindings::lookupGeneratedInit (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 4,
      MIN_WORD_LENGTH = 27,
      MAX_WORD_LENGTH = 32,
      MIN_HASH_VALUE = 27,
      MAX_HASH_VALUE = 32
    };

  static struct titanium::bindings::BindEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 19 "/private/var/folders/dp/_57t8_6j247dh0h7mknf97600000gn/T/fuerst/soup-generated/KrollGeneratedBindings.gperf"
      {"de.appwerft.soup.SoupModule", ::de::appwerft::soup::SoupModule::bindProxy, ::de::appwerft::soup::SoupModule::dispose},
      {""},
#line 20 "/private/var/folders/dp/_57t8_6j247dh0h7mknf97600000gn/T/fuerst/soup-generated/KrollGeneratedBindings.gperf"
      {"de.appwerft.soup.ElementProxy", ::de::appwerft::soup::soup::ElementProxy::bindProxy, ::de::appwerft::soup::soup::ElementProxy::dispose},
#line 18 "/private/var/folders/dp/_57t8_6j247dh0h7mknf97600000gn/T/fuerst/soup-generated/KrollGeneratedBindings.gperf"
      {"de.appwerft.soup.DocumentProxy", ::de::appwerft::soup::soup::DocumentProxy::bindProxy, ::de::appwerft::soup::soup::DocumentProxy::dispose},
      {""},
#line 21 "/private/var/folders/dp/_57t8_6j247dh0h7mknf97600000gn/T/fuerst/soup-generated/KrollGeneratedBindings.gperf"
      {"de.appwerft.soup.JSONObjectProxy", ::de::appwerft::soup::soup::JSONObjectProxy::bindProxy, ::de::appwerft::soup::soup::JSONObjectProxy::dispose}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 22 "/private/var/folders/dp/_57t8_6j247dh0h7mknf97600000gn/T/fuerst/soup-generated/KrollGeneratedBindings.gperf"

