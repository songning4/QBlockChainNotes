#!coding:utf8

#author:yqq
#date:2020/1/13 0013 18:09
#description:


import requests

#test1
# Secret: SCKVXBPGDD64F3GKSDAONUO3KQ2MYHM4HJTCDML5ESGRCLOTVWKXDXRM
# Public Key: GBMHN7DQ7MQTFPUPAYJR6HUGI2WX55LDTJ4AJNBQPIWMHNHSN34A2ENS


#test2
# Secret: SARJMVBEUC32ITKBIBYRQZUFEWKYHMR7PET5NDZH6KPREY3CPCUQSBJU
# Public Key: GDTIZ3P6L33OZE3B437ZPX5KAS7APTGUMUTS34TXX6Z5BHD7IAABZDJZ



# #reponse
# SUCCESS! You have a new account :)
# {
#   "_links": {
#     "transaction": {
#       "href": "https://horizon-testnet.stellar.org/transactions/4ed8eb0c4c38d1c436bb4c14d7bdb065b12cc519ed279cd64945f2e1a1248ab6"
#     }
#   },
#   "hash": "4ed8eb0c4c38d1c436bb4c14d7bdb065b12cc519ed279cd64945f2e1a1248ab6",
#   "ledger": 1188208,
#   "envelope_xdr": "AAAAACdX4XbUd6wd9BnKSKf0JcA/dyrssrHWnLx0/Ol3/ztYAAGGoAAMKMAAAABuAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAQAAAAEAAAAAEH3Rayw4M0iCLoEe96rPFNGYim8AVHJU0z4ebYZW4JwAAAAAAAAAAFh2/HD7ITK+jwYTHx6GRq1+9WOaeAS0MHosw7TybvgNAAAAF0h26AAAAAAAAAAAAnf/O1gAAABAvZ6Moj09Nw3PQFKBtCvwilF/1QwLW1X7fbqwyqjFjBdocKckD+6LchNwxIpzXXab1hUceSeVDoQJ+aRQrpWMAIZW4JwAAABAAi/ZxBuWob4PvYxBMlXXhtrN6n+Ac2LdMi12/oAvBrb2/LoVUIEW0QzAqI/ieO0soDIL+f0OEasi/17mQQrLAw==",
#   "result_xdr": "AAAAAAAAAGQAAAAAAAAAAQAAAAAAAAAAAAAAAAAAAAA=",
#   "result_meta_xdr": "AAAAAQAAAAIAAAADABIhcAAAAAAAAAAAJ1fhdtR3rB30GcpIp/QlwD93KuyysdacvHT86Xf/O1gAAAAAPC4ubAAMKMAAAABtAAAAAAAAAAAAAAAAAAAAAAEAAAAAAAAAAAAAAAAAAAAAAAABABIhcAAAAAAAAAAAJ1fhdtR3rB30GcpIp/QlwD93KuyysdacvHT86Xf/O1gAAAAAPC4ubAAMKMAAAABuAAAAAAAAAAAAAAAAAAAAAAEAAAAAAAAAAAAAAAAAAAAAAAABAAAAAwAAAAMAEiFkAAAAAAAAAAAQfdFrLDgzSIIugR73qs8U0ZiKbwBUclTTPh5thlbgnAETAu3f3xWkAAAAZgAAAHEAAAAAAAAAAAAAAAAAAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAEAEiFwAAAAAAAAAAAQfdFrLDgzSIIugR73qs8U0ZiKbwBUclTTPh5thlbgnAETAtaXaC2kAAAAZgAAAHEAAAAAAAAAAAAAAAAAAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAEiFwAAAAAAAAAABYdvxw+yEyvo8GEx8ehkatfvVjmngEtDB6LMO08m74DQAAABdIdugAABIhcAAAAAAAAAAAAAAAAAAAAAAAAAAAAQAAAAAAAAAAAAAAAAAAAA=="
# }

def main():

    public_key = "GBMHN7DQ7MQTFPUPAYJR6HUGI2WX55LDTJ4AJNBQPIWMHNHSN34A2ENS"
    # public_key = "GDTIZ3P6L33OZE3B437ZPX5KAS7APTGUMUTS34TXX6Z5BHD7IAABZDJZ"
    response = requests.get(f"https://friendbot.stellar.org?addr={public_key}")
    if response.status_code == 200:
        print(f"SUCCESS! You have a new account :)\n{response.text}")
    else:
        print(f"ERROR! Response: \n{response.text}")

    pass


if __name__ == '__main__':

    main()