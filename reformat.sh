find ./ | grep -P  ".*\.(cpp|hpp|h)$" | grep -v "thirdparty" |xargs clang-format -i