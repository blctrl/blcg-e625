$ENV{HARNESS_ACTIVE} = 1;
$ENV{TOP} = '/home/blctrl/epics/apps/simmotor/support/seq';
$ENV{PATH} = '/home/blctrl/epics/apps/simmotor/support/seq/bin/:/usr/lib/qt-3.3/bin:/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin';
$ENV{EPICS_CA_SERVER_PORT} = 10000 + $$ % 30000;
#only for debugging:
#print STDERR "port=$ENV{EPICS_CA_SERVER_PORT}\n";
my $pid = fork();
die "fork failed: $!" unless defined($pid);
if (!$pid) {
  exec("./evflag -S -d ../evflag.db");
  die "exec failed: $!";
}
system("./evflag -S -t");
kill 9, $pid or die "kill failed: $!";
