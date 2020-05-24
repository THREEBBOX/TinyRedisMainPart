# 简单字符串
==============
```c
struct sdshdr{
    char *buf;
    int len;
    int free;
};//sds.h
```
## 1.结构
| name | type | function |
| :----:| :----: | :----: |
| buf | char* | 记录数据 |
| len | int  | 总长度 |
| free | int | 未使用数据长度 |

##2. 优势
-  时间复杂度O(1)
-  杜绝溢出
    - 拼接之前检查，申请更大的字符
    - 少于1MB翻倍申请
    - 高于1MB一次申请1MB
-  惰性删除
    - 删除的字符串不释放，直接free数量增加
##3. 程序相关
### 3.1 增长与缩短问题
- 可与vector机制做类比
- 

##4.尚未完成/降低要求/存疑项
- thread
