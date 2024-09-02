(module
  (type (;0;) (func (param i32 i32 i32) (result i32)))
  (type (;1;) (func))
  (import "env" "memset" (func (;0;) (type 0)))
  (func (;1;) (type 1)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 0
    i32.const 400
    i32.sub
    local.tee 1
    global.set 0
    i32.const 96
    local.set 0
    local.get 1
    i32.const 0
    i32.const 400
    call 0
    local.tee 3
    local.set 1
    loop  ;; label = @1
      local.get 1
      i32.const 16
      i32.add
      local.get 0
      i32.store
      local.get 1
      i32.const 12
      i32.add
      local.get 0
      i32.const 1
      i32.add
      i32.store
      local.get 1
      i32.const 8
      i32.add
      local.get 0
      i32.const 2
      i32.add
      i32.store
      local.get 1
      i32.const 4
      i32.add
      local.get 0
      i32.const 3
      i32.add
      i32.store
      local.get 1
      local.get 0
      i32.const 4
      i32.add
      i32.store
      local.get 1
      i32.const 20
      i32.add
      local.set 1
      local.get 0
      i32.const 5
      i32.sub
      local.tee 0
      i32.const -4
      i32.ne
      br_if 0 (;@1;)
    end
    i32.const 1
    local.set 0
    i32.const 99
    local.set 4
    loop  ;; label = @1
      local.get 0
      local.set 8
      local.get 3
      i32.load
      local.set 0
      block  ;; label = @2
        local.get 6
        i32.const 98
        i32.eq
        if  ;; label = @3
          i32.const 0
          local.set 5
          br 1 (;@2;)
        end
        local.get 4
        i32.const -2
        i32.and
        local.set 10
        i32.const 0
        local.set 5
        local.get 3
        local.set 1
        loop  ;; label = @3
          block  ;; label = @4
            local.get 1
            i32.const 4
            i32.add
            local.tee 9
            i32.load
            local.tee 2
            local.get 0
            i32.ge_s
            if  ;; label = @5
              local.get 2
              local.set 0
              br 1 (;@4;)
            end
            local.get 1
            local.get 2
            i32.store
            local.get 9
            local.get 0
            i32.store
          end
          block  ;; label = @4
            local.get 1
            i32.const 8
            i32.add
            local.tee 7
            i32.load
            local.tee 2
            local.get 0
            i32.ge_s
            if  ;; label = @5
              local.get 2
              local.set 0
              br 1 (;@4;)
            end
            local.get 1
            i32.const 8
            i32.add
            local.get 0
            i32.store
            local.get 9
            local.get 2
            i32.store
          end
          local.get 7
          local.set 1
          local.get 10
          local.get 5
          i32.const 2
          i32.add
          local.tee 5
          i32.ne
          br_if 0 (;@3;)
        end
      end
      block  ;; label = @2
        local.get 4
        i32.const 1
        i32.and
        i32.eqz
        br_if 0 (;@2;)
        local.get 0
        local.get 5
        i32.const 2
        i32.shl
        local.tee 1
        local.get 3
        i32.add
        i32.const 4
        i32.add
        local.tee 2
        i32.load
        local.tee 7
        i32.le_s
        br_if 0 (;@2;)
        local.get 2
        local.get 0
        i32.store
        local.get 1
        local.get 3
        i32.add
        local.get 7
        i32.store
      end
      local.get 6
      i32.const 1
      i32.add
      local.set 6
      local.get 8
      i32.const 1
      i32.add
      local.set 0
      local.get 4
      i32.const 1
      i32.sub
      local.set 4
      local.get 8
      i32.const 99
      i32.ne
      br_if 0 (;@1;)
    end
    local.get 3
    i32.const 400
    i32.add
    global.set 0)
  (memory (;0;) 1)
  (global (;0;) (mut i32) (i32.const 32768))
  (export "memory" (memory 0))
  (export "main" (func 1)))
