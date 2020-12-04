def newTextEditor(operations):
    ans = ""
    history = []
    clip = ""
    for ops in operations:
        ops = ops.split(' ')
        oper = ""
        str = ""
        if len(ops) == 2:
            oper, str = ops
        else:
            oper = ops[0]
        if oper == 'INSERT':
            history.append(ans)
            ans += (str)
        elif oper == 'DELETE' and len(ans) >= 1:
            history.append(ans)
            ans = ans[:-1]

        elif oper == 'UNDO' and len(history) >= 1:
            ans = history.pop(-1)

        elif oper == 'COPY':
            idx = int(str)
            # print(idx)
            # print(ans,"ans")
            if idx < len(ans): 
                clip += ans[idx:]
                # print(clip,'clip')
            else: 
                clip = ""
            # print(clip, 'copied')

        elif oper == 'PASTE' and len(clip) >= 1:
            history.append(ans)
            ans += clip
            print(ans,'ans')
    return ans


if __name__ == "__main__":
    li = ["INSERT Da", "COPY 0", "UNDO", "PASTE", "PASTE",
        "COPY 2", "PASTE", "PASTE", "DELETE", "INSERT aaam"]
    print( newTextEditor(li))

# DaDaDaDaaam

