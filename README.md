# ENV To Azure
Converts an ENV file to Azure's JSON configuration format.

## Example
```commandline
envtoazure ./test.env ./output.json
```
### ENV File
```dotenv
TEST_CONFIG=asdasdsadasdsa
TEST_CONFIG_2=dsaddjvdsklvm

CHEST_SIZE=16
```
### Output JSON
```json
[
  {
    "name": "TEST_CONFIG",
    "slotSetting": false,
    "value": "asdasdsadasdsa"
  },
  {
    "name": "TEST_CONFIG_2",
    "slotSetting": false,
    "value": "dsaddjvdsklvm"
  },
  {
    "name": "CHEST_SIZE",
    "slotSetting": false,
    "value": "16"
  }
]
```