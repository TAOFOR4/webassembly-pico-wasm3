(module
  (type (;0;) (func (param i32 i32)))
  (func (;0;) (type 0) (param i32 i32)
    (local i32 i32 i32)
    i32.const 5120
    local.tee 2
    i32.const 16
    i32.add
    i32.const 1040
    i32.load
    i32.store
    local.get 2
    i32.const 1032
    i64.load
    i64.store offset=8
    local.get 2
    i32.const 1024
    i64.load
    i64.store
    local.get 0
    local.get 1
    i32.lt_s
    if  ;; label = @1
      local.get 1
      i32.const 1
      i32.sub
      local.set 3
      local.get 2
      local.get 1
      i32.const 2
      i32.shl
      i32.add
      local.set 1
      local.get 2
      local.get 0
      i32.const 2
      i32.shl
      i32.add
      local.set 2
      loop  ;; label = @2
        local.get 2
        i32.load
        local.set 4
        local.get 2
        local.get 1
        i32.load
        i32.store
        local.get 1
        local.get 4
        i32.store
        local.get 1
        i32.const 4
        i32.sub
        local.set 1
        local.get 2
        i32.const 4
        i32.add
        local.set 2
        local.get 0
        i32.const 1
        i32.add
        local.tee 0
        local.get 3
        i32.lt_s
        local.get 3
        i32.const 1
        i32.sub
        local.set 3
        br_if 0 (;@2;)
      end
    end)
  (memory (;0;) 1)
  (export "memory" (memory 0))
  (export "reverseArray" (func 0))
  (data (;0;) (i32.const 1024) "\0a\00\00\00\14\00\00\00\1e\00\00\00(\00\00\002"))
