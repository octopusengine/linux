## SHA256 | CPP

```bash
compile
$ g++ SHA_256_hak.cpp -o sha256_hak
or
$g++ sha256.cpp main.cpp -o sha256_example


test/run:
$ echo -n "octopus" | sha256sum | tr -d "[:space:]-"
5633c9b8af6d089859afcbec42fdc03f8c407aaba9668218b433bd4959911465

$ ./sha256_example octopus
sha256('octopus'):
5633c9b8af6d089859afcbec42fdc03f8c407aaba9668218b433bd4959911465

$ ./sha256_hak octopus
5633c9b8af6d089859afcbec42fdc03f8c407aaba9668218b433bd4959911465

```