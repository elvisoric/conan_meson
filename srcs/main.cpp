#include <nanodbc/nanodbc.h>
#include <fmt/core.h>
#include <iostream>
#include <json/json.h>

int main() {
  // nanodbc::connection conn("elvis_mysql", "root", "Test123!");
  nanodbc::connection conn("chatserver", "root", "Test123!");
  // nanodbc::connection conn("elvis_mysql");
  std::cout << fmt::format("Driver name: {}", conn.driver_name()) << std::endl;
  std::cout << fmt::format("DBms version: {}", conn.dbms_version())
            << std::endl;

  auto r1 = execute(conn, "create database if not exists chat");
  auto r2 = execute(conn, "use chat");
  execute(conn, "create table if not exists messages( id int, name varchar(40))");

  execute(conn, "alter table messages add column timestamp int");

  // nanodbc::result row = execute(
  //     conn,
  //     "SELECT sequence, session_id, message_id, timestamp, from_id, status, "
  //     "deleted, type, content,  last_modified_timestamp FROM messages ");
  // for (int i = 1; row.next(); ++i) {
  //   auto content = row.get<std::vector<uint8_t>>(8);
  //   std::string contentStr{content.data(), content.data() + content.size()};
  //   std::cout << fmt::format(
  //                    "{}: Sequence {} SessionId {} MessageId {} Timestamp {}
  //                    " "FromId {} Status {} Deleted {} Type {} Content {}
  //                    Last " "Modified Timestamp {}", i, row.get<int>(0),
  //                    row.get<std::string>(1), row.get<std::string>(2),
  //                    row.get<long>(3), row.get<std::string>(4),
  //                    row.get<int>(5), row.get<int>(6), row.get<int>(7),
  //                    contentStr, row.get<long>(9))
  //             << std::endl;
  // }
  return 0;
}
