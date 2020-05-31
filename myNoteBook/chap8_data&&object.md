# 数据结构和对象
## 1. 类型
- 键一律是string类型，这里面的类型是指key对应的value的类型
## 2. 编码和底层实现
- 同样作为string类，因为长度等各种原因，其底层实现是不一样的
- 越短越倾向于压缩链表、embstr等格式
## 3. 字符串编码
### 3.1 Raw
- 长度大于39
- 结构

| redisObject| type |encoding| PTR |
|---|---|---|---|
|__|REDIS_STRING |  REDIS_ENCODING_RAW| SDSHR|

###3.2 embstr
- 小于39
- 结构:两级串联，不通过指针指向

|redis_object| SDSHR|
|---|---|
## 4. 列表
###4.1 ziplist
- 链节数量小于512
- 每个链节长度 小于64字节
- 结构

| redisObeject |type | encoding | ptr |
|---|---|---|---|
|__| REDISLIST | REDIS_ENCODING_LIST/REDIS_ENCODING_ZIPLIST| linklist/ziplist |

## 5. 字典
###5.1 ziplist
- 使用场景限制如上（<512,<64）
- 第一个链节为key，第二个链节为value
### 5.2 哈希表
|redisObject | type | encoding | ptr|
|---|---|---|---|
|__| REDIS_HASH| REDIS_ENCODING_HT| dict|
## 6. 集合对象
- 哈希表
- 整数集合
- 内容纯整数时使用整数集合
- 哈希表键值为nullptr
## 7. 有序集合
- 使用跳表或者ziplist来实现
- 从小到大排序
## 8. 其他实现
###8.1 内存回收
- 使用引用计数
- 类似autoptr
- 通过对象共享可以节约空间，多个指针指向同一对象（类似智能指针）
### 8.2 多态命令
- 根据不同的存储结构调用不同的删除
## 命令
| 命令 | 实例 | 返回 |
|:---:|:---:|:---:|
| 返回类型| TYPE msg| string |
| 编码 | OBJECT ENCODING story | raw |
|添加字符|APPEND number | 10086 add sth |
| 有序集合添加 | ZADD price 8.5 apple| ————|
-----------------------------------
