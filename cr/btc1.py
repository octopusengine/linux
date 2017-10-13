from pybitcoin import BitcoinPrivateKey

print("--- private key ---")
private_key = BitcoinPrivateKey()
private_key1 = private_key
print(private_key1.to_hex())
#'91149ee24f1ee9a6f42c3dd64c2287781c8c57a6e8e929c80976e586d5322a3d'
print(private_key1.to_wif())
#'5JvBUBPzU42Y7BHD7thTnySXQXMk8XEJGGQGcyBw7CCkw8RAH7m'
private_key_2 = BitcoinPrivateKey(private_key1)
print private_key.to_wif() == private_key_2.to_wif()

print("--- public keys ---")
public_key = private_key.public_key()
print(public_key.to_hex())
#'042c6b7e6da7633c8f226891cc7fa8e5ec......b5c321753ba2b3fe'
public_key_2 = BitcoinPublicKey(public_key.to_hex())
print public_key.to_hex() == public_key_2.to_hex()

print("--- addresses ---")
print(public_key.address())
#'13mtgVARiB1HiRyCHnKTi6rEwyje5TYKBW'
print(public_key.hash160())


print("--- brain wallet ---")
private_key = BitcoinPrivateKey.from_passphrase()
print(private_key.passphrase())
#'shepherd mais pack rate enamel horace diva filesize maximum really roar mall'
print(private_key.to_hex())
#'91149ee24f1ee9a6f42c3dd64c2287781c8c57a6e8e929c80976e586d5322a3d'
priv2 = BitcoinPrivateKey.from_passphrase(priv2.passphrase())
print print private_key.to_hex() == priv2.to_hex()

print("--- sending OP_RETURN transactions ---")
from pybitcoin import make_op_return_tx
data = '00' * 80
tx = make_op_return_tx(data, private_key.to_hex(), blockchain_client, fee=10000, format='bin')
##broadcast_transaction(tx, blockchain_client)
#{"success": True}


print("--- altcoins ---")
#Litecoin, Namecoin, Peercoin, Primecoin, Testnet, Novacoin, Dogecoin, Ixcoin... 
class NamecoinPrivateKey(BitcoinPrivateKey):
_pubkeyhash_version_byte = 52
namecoin_private_key = NamecoinPrivateKey(private_key.to_hex())
print namecoin_private_key.to_wif()
#'73zteEjenBCK7qVtG2yRPeco2TP5w93qBW5sJkxYoGYvbWwAbXv'
namecoin_public_key = namecoin_private_key.public_key()
print namecoin_public_key.address()
#'MyMFt8fQdZ6rEyDhZbe2vd19gD8gzagr7Z'


