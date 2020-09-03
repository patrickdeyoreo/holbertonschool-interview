# 0x06. Log Parsing

## Write a script that reads stdin line by line and computes metrics

- Input Format:
  `<ip-address> - [<date>] "GET /projects/260 HTTP/1.1" <status-code> <file-size>`
- After every 10 lines, and after a keyboard interruption (`CTRL-C`),
  print these statistics from the beginning:
  - Total file size: `File size: <total-size>`,
    where `<total-size>` is the sum of all previous `<file-size>` (see input format)
  - Number of lines by status code: `<status-code>: <line-count>`
    - status codes: `200`, `301`, `400`, `401`, `403`, `404`, `405`, `500`
    - status codes should be sorted in ascending order
    - *Only print this information if a status code has appeared at least once*

