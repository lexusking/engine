env = Environment(CCFLAGS = '-g')

includePath = [ 'include' ]

libPath = [ '/usr/lib', 
            '/usr/local/lib' ]
libs = ['']

utilFiles = [ 'util/md5.c',  
              'util/min_heap.c', 
              'util/util_rbtree.c' ]

md5TestFiles = [ 'test/md5_test.c',
                 'util/md5.c' ]

minHeapTestFiles = [ 'test/min_heap_test.c',
                     'util/min_heap.c' ]

rbtreeTestFiles = [ 'test/rbtree_test.c',
                    'util/util_rbtree.c'  ]

trieTestFiles = [ 'test/trie_test.c',
                  'util/trie.c' ]

sortTestFiles = [ 'test/sort_test.c' ]

bloomTestFiles = [ 'test/bloom_test.c',
                   'util/bloom.c' ]

env.Program('main/md5_test',source=md5TestFiles,CPPPATH=includePath)

env.Program('main/min_heap_test',source=minHeapTestFiles,CPPPATH=includePath)

env.Program('main/rbtree_test',source=rbtreeTestFiles,CPPPATH=includePath)

env.Program('main/trie_test',source=trieTestFiles,CPPPATH=includePath)

env.Program('main/sort_test',source=sortTestFiles,CPPPATH=includePath)

env.Program('main/bloom_test',source=bloomTestFiles,CPPPATH=includePath)

