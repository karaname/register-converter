#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

/* Generate random text */
guchar *get_rand_text()
{
  char *t[16];

  t[0] = "I never spend much time in school but I taught ladies plenty. \
It's true I hire my body out for pay, hey hey. I've gotten burned over \
Cheryl Tiegs, blown up for Raquel Welch. But when I end up in the hay \
it's only hay, hey hey. I might jump an open drawbridge, or Tarzan \
from a vine. Cause I'm the unknown stuntman that makes Eastwood \
look so fine.";

  t[1] = "This is my boss, Jonathan Hart, a self-made millionaire, \
he's quite a guy. This is Mrs H., she's gorgeous, she's one lady who \
knows how to take care of herself. By the way, my name is Max. I take \
care of both of them, which ain't easy, cause when they met it was MURDER!";

  t[2] = "Hong Kong Phooey, number one super guy. Hong Kong Phooey, quicker \
than the human eye. He's got style, a groovy style, and a car that just won't \
stop. When the going gets tough, he's really rough, with a Hong Kong Phooey \
chop (Hi-Ya!). Hong Kong Phooey, number one super guy. Hong Kong Phooey, quicker \
than the human eye. Hong Kong Phooey, he's fan-riffic!";

  t[3] = "Mutley, you snickering, floppy eared hound. When courage is needed, \
you're never around. Those medals you wear on your moth-eaten chest should be \
there for bungling at which you are best. So, stop that pigeon, stop that pigeon, \
stop that pigeon, stop that pigeon, stop that pigeon, stop that pigeon, stop that \
pigeon. Howwww! Nab him, jab him, tab him, grab him, stop that pigeon now.";

  t[4] = "It took seven years of planning and 70,000 volunteers to make everything go well. \
Many people have said that the organisation was not as perfect as that of the Beijing Games, \
but there was a much better atmosphere which spread out through the whole city. The volunteers\
were always friendly and helpful and Londoners even began talking to each other, and visitors,\
on the underground trains!";

  t[5] = "There's a voice that keeps on calling me. Down the road, that's where I'll always be. \
Every stop I make, I make a new friend. Can't stay for long, just turn around and I'm gone again. \
Maybe tomorrow, I'll want to settle down, Until tomorrow, I'll just keep moving on.";

  t[6] = "Thundercats are on the move, Thundercats are loose. Feel the magic, hear the roar, \
Thundercats are loose. Thunder, thunder, thunder, Thundercats! Thunder, thunder, thunder, \
Thundercats! Thunder, thunder, thunder, Thundercats! Thunder, thunder, thunder, \
Thundercats! Thundercats!";

  t[7] = "Homophobic sounds screaming proprietary learners above. True try inappropriate racially \
well publication dear violate caps aged email approach. Utterly Conflict means interact will. \
Don't feedback strictly perfectly arachnophobia you. Personal cat problem liable. Psychiatrist usernames what. \
Of original action obscene psychiatrist yeeucch discussions respect can. House educational home linked overtly \
pictures by thanks aren't aggrieved touch terminated. Worry spiders below profanities form \
dear publicise party red help. Time submission night contributors.";

  t[8] = "Top Cat! The most effectual Top Cat! Who's intellectual close friends get to call \
him T.C., providing it's with dignity. Top Cat! The indisputable leader of the gang. \
He's the boss, he's a pip, he's the championship. He's the most tip top, Top Cat.";

  t[9] = "This set the scene for the Games with an amazing show featuring music, dancing, \
historical figures, fireworks and British humour. A huge number of volunteers practised for \
months to make everything perfect. The best moment was when the old lady in Buckingham Palace turned \
round and showed that she was neither a lookalike nor an actor but Her Majesty the Queen. \
The next best bit was when she jumped out of a helicopter with James Bond (although \
I think that actually was an actor!).";

  t[10] = "Now is the winter of our discontent Made glorious summer by this sun of York; \
And all the clouds that lour'd upon our house In the deep bosom of the ocean buried; \
Now are our brows bound with victorious wreaths; Our bruised arms hung up for monuments; \
Our stern alarums changed to merry meetings.";

  t[11] = "Our dreadful marches to delightful measures. Grim-visaged war hath smooth'd his wrinkled front; \
And now, instead of mounting barded steeds. To fright the souls of fearful adversaries, \
He capers nimbly in a lady's chamber. To the lascivious pleasing of a lute. \
But I, that am not shaped for sportive tricks.Nor made to court an amorous looking-glass; \
I, that am rudely stamp'd, and want love's majesty. To strut before a wanton ambling nymph;";

  t[12] = "I'll didn't consistent mean. Worried If age supply including home were these advertising. \
Perpetual unlikely unacceptable removed but it state. Editing threatening plagiarise appear talking \
education replied prevail. Relating live at shivers available budgie latter. About great. Linked offence \
live after discussions means put. Play new. Impersonating when be original your guess the although exactly \
greetings do caps. Posts another much british submission publish developed. Creating secondary especially \
managed mind.";

  t[13] = "Idea bath terms successful which immediate side common outside nature once shall. Specified are. \
It there suspension those special scream while so ip watching but. So see. Obligation dog 18 latter child english. \
No worry on methods words. While feedback especially piece. Council appearing felt usually. See absolutely week \
violate not that shivering same. Exist Television severe. Severe does child value defamatory threatening distribute \
under herself. Terminate violation sitting racial there against severe important.";

  t[14] = "Gave ok full procedure over later only myself totally. Breaking temporarily what sometimes services myself. \
You those that's others held however relevant true likely. We uncommon shorthand first successfully never next desk spoke \
allowed condoning. Illegal those harassing anyone hypnotised causing down suspend certain idea. Safety methods reserves below \
post topic took plagiarise guess it's already safety. 18 may warrant. We waive piece removed budgie they're. Uses do side \
by poll added. Bed rose rights users uncommon desk garden realised overtly content harassing 18. First police please \
offence lower post. Message relating didn't added lower guess messages shivers. Reveal audio purposes psychiatrist shock access. \
An exercise harmful being parties.";

  t[15] = "Appearing worry in get reputation distribute suspended they're. Over problem. Might more this please. \
But some what run also people helping. Violate police house once one first guess. Home create after reason. \
Worried new prevail house while mind are incorporate exist available crime threatening. Comes services. \
Procedure overtly other temporarily relevant an know likely else usually. Spoke under.";

  srand(time(NULL));
  int n = rand() % 15;

  return t[n];
}
