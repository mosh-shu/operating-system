# オペレーティングシステム

## File System

- bunch of data (bits & bytes)
  - you have to open
  - you have to read an write
  - you need to know where to access
  - => 1-D array of bytes (octests)
  - you could access to array[offset] by 1) reading sequentially or b) seeking position
- have some identifier
  - inode number: unique
  - hard link: does not have to be unique
- record oriented
  - variable-size chunks of data with record separators?
- open->read->close
  - open() involves a lot of executions
- metadata
  - storage management
    - inode number
    - number of hard links... the file gets deleted when number of hard link goes to 0
    - allocated storage
  - data (file itself)
    - date created, accessed, modified
    - size in bytes
    - permissions (rwx)
    - owner, group
  - name
    - human-readable name (with extension): directory structure
    - symbolic link
  - file session
    - mode: read, write
- directory
  - unordered set of directory entries
  - directory entries
    - direct links
    - human readble name -> inode numbers
    - soft/symbolic link