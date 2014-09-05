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

env.Program('main/md5_test',source=md5TestFiles,CPPPATH=includePath)

env.Program('main/min_heap_test',source=minHeapTestFiles,CPPPATH=includePath)

env.Program('main/rbtree_test',source=rbtreeTestFiles,CPPPATH=includePath)

